Status ListInsert_L(NLinkList L, int i, ElemType e) {  // �㷨2.20
  // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
  NLink h,s;
  if (!LocatePos(L, i-1, h))  
    return ERROR;  // iֵ���Ϸ�
  if (!MakeNode(s, e))
    return ERROR;  // ���洢����ʧ��
  InsFirst(h, s);  // ���ڴӵ�i��㿪ʼ����������i-1���������ͷ���
  return OK;
}  // ListInsert_L