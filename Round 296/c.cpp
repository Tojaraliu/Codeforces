#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Fordown(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

struct node
{
    int ll,rr,heap;
    node *lch,*rch;
};

struct tnode
{
    int data,heap;
    tnode *lch,*rch;
};

node *bstv,*bsth;
tnode *bstlv,*bstlh;
int n,m,k;

void sqrrot(node *&p)
{
    node *q=p->lch;
    p->lch=q->rch;
    q->rch=p;
    p=q;
}

void sqlrot(node *&p)
{
    node *q=p->rch;
    p->rch=q->lch;
    q->lch=p;
    p=q;
}

void sqinsert(int ll,int rr,node *&t)
{
    if (t==NULL) {
        t=new node;
        t->lch=t->rch=NULL;
        t->ll=ll;t->rr=rr;
        t->heap=rand()%10000007;
    }
    else if (t->ll==ll) return;
    else if (rr<t->ll){
        sqinsert(ll,rr,t->lch);
        if (t->lch->heap > t->heap) sqrrot(t);
    }
    else {
        sqinsert(ll,rr,t->rch);
        if (t->rch->heap > t->heap) sqlrot(t);
    }
}

void sqdel(node *&p,int n)
{
    if (p==NULL) return;
    if (n>p->ll) sqdel(p->rch,n);
    else if (n<p->ll) sqdel(p->lch,n);
    else {
        if (p->rch==NULL && p->lch==NULL){
            delete p;p=NULL;
            return;
        }
        else if (p->lch==NULL){
            node *q=p;
            p=p->rch;
            delete q;
        }
        else if (p->rch==NULL){
            node *q=p;
            p=p->lch;
            delete q;
        }
        else {
            if (p->rch->lch==NULL) {
                p->ll=p->rch->ll;
                p->rr=p->rch->rr;
                sqdel(p->rch,p->rch->ll);
            }
            else {
                node *q=p->rch;
                while (q->lch->lch!=NULL) q=q->lch;
                p->ll=q->lch->ll;
                p->rr=q->lch->rr;
                sqdel(q->lch,q->lch->ll);
            }
        }
    }
}

void sqmid(node *&p)
{
    if (p==NULL) return;
    sqmid(p->lch);
    printf("(%d,%d)\n", p->ll,p->rr);
    sqmid(p->rch);
    return;
}

int sqdep(node *p)
{
    if (p!=NULL) {
        return max(sqdep(p->lch),sqdep(p->rch))+1;
    }
    return 0;
}

void sqfind(node *&p,int n,int &ll,int &rr)
{
    if ((p->ll<n && n<p->rr)||(p->ll==n)||(p->rr==n)) {
        ll=p->ll;rr=p->rr;
        sqdel(p,p->ll);
    }
    else if (n>p->rr) sqfind(p->rch,n,ll,rr);
    else if (n<p->ll) sqfind(p->lch,n,ll,rr);
}

int findl(node *p)
{
    if (p==NULL) return 0;
    return max(max(findl(p->lch),findl(p->rch)),p->rr-p->ll+1);
}

void rrot(tnode *&p)
{
    tnode *q=p->lch;
    p->lch=q->rch;
    q->rch=p;
    p=q;
}

void lrot(tnode *&p)
{
    tnode *q=p->rch;
    p->rch=q->lch;
    q->lch=p;
    p=q;
}

void insert(int n,tnode *&t)
{
    if (t==NULL) {
        t=new tnode;
        t->lch=t->rch=NULL;
        t->data=n;
        t->heap=rand()%10000007;
    }
    else if (n<=t->data){
        insert(n,t->lch);
        if (t->lch->heap > t->heap) rrot(t);
    }
    else {
        insert(n,t->rch);
        if (t->rch->heap > t->heap) lrot(t);
    }
}

void del(tnode *&p,int n)
{
    if (p==NULL) return;
    if (n>p->data) del(p->rch,n);
    else if (n<p->data) del(p->lch,n);
    else {
        if (p->rch==NULL && p->lch==NULL){
            delete p;p=NULL;
            return;
        }
        else if (p->lch==NULL){
            tnode *q=p;
            p=p->rch;
            delete q;
        }
        else if (p->rch==NULL){
            tnode *q=p;
            p=p->lch;
            delete q;
        }
        else {
            if (p->rch->lch==NULL) {
                p->data=p->rch->data;
                del(p->rch,p->rch->data);
            }
            else {
                tnode *q=p->rch;
                while (q->lch->lch!=NULL) q=q->lch;
                p->data=q->lch->data;
                del(q->lch,q->lch->data);
            }
        }
    }
}

void mid(tnode *&p)
{
    if (p==NULL) return;
    mid(p->lch);
    printf("%d ", p->data);
    mid(p->rch);
    return;
}

int dep(tnode *p)
{
    if (p!=NULL) {
        return max(dep(p->lch),dep(p->rch))+1;
    }
    return 0;
}

int findmax(tnode *p)
{
    while (p->rch!=NULL) p=p->rch;
    return p->data;
}

void Init()
{
    bstv=NULL;bsth=NULL;
    bstlv=NULL;bstlh=NULL;
    int tmp;
    char ch;
    scanf("%d %d %d",&n,&m,&k);
    ch=getchar();
    sqinsert(1,n,bstv);sqinsert(1,m,bsth);
    insert(n,bstlv);insert(m,bstlh);
    For(i,1,k){
        scanf("%c",&ch);
        while (ch=='\n') scanf("%c",&ch);
        scanf("%d",&tmp);
        if (ch=='V') {
            node *p;
            if (bstv->ll<tmp && tmp<bstv->rr) {
                int tmpl=bstv->ll,tmpr=bstv->rr;
                sqdel(bstv,tmpl);del(bstlv,tmpr-tmpl+1);
                sqinsert(tmpl,tmp,bstv);sqinsert(tmp+1,tmpr,bstv);
                insert(tmp-tmpl+1,bstlv);insert(tmpr-tmp,bstlv);
            }
            else {
                int tmpl,tmpr;
                sqfind(bstv,tmp,tmpl,tmpr);
                del(bstlv,tmpr-tmpl+1);
                sqinsert(tmpl,tmp,bstv);sqinsert(tmp+1,tmpr,bstv);
                insert(tmp-tmpl+1,bstlv);insert(tmpr-tmp,bstlv);
            }
        }
        else if (ch=='H') {
            node *p;
            if (bsth->ll<tmp && tmp<bsth->rr) {
                int tmpl=bsth->ll,tmpr=bsth->rr;
                sqdel(bsth,tmpl);del(bstlh,tmpr-tmpl+1);
                sqinsert(tmpl,tmp,bsth);sqinsert(tmp+1,tmpr,bsth);
                insert(tmp-tmpl+1,bstlh);insert(tmpr-tmp,bstlh);
            }
            else {
                int tmpl,tmpr;
                sqfind(bsth,tmp,tmpl,tmpr);
                del(bstlh,tmpr-tmpl+1);
                sqinsert(tmpl,tmp,bsth);sqinsert(tmp+1,tmpr,bsth);
                insert(tmp-tmpl+1,bstlh);insert(tmpr-tmp,bstlh);
            }        }
        printf("%I64d\n",(long long int)findmax(bstlh)*(long long int)findmax(bstlv));
    }
}

int main() {
    
    Init();
    Main();
    
    return 0;
}