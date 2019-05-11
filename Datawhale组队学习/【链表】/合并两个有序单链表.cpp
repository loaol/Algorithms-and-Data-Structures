void MergeList_List_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LinkList pa=La->next,pb=Lb->next,pc;
    Lc=pc=La;      //用La的头结点作为Lc的头结点
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;   //插入剩余段
    free(Lb);            //释放Lb的头结点
}
