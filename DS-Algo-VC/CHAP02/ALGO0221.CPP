Status MergeList_L(NLinkList &La, NLinkList &Lb, NLinkList &Lc, 
                 int (*compare)(ElemType, ElemType)) {  // �㷨2.21
  // ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
  // �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
  NLink ha, hb;
  Position pa, pb, q;
  ElemType a, b;
  if (!InitList(Lc)) return ERROR;  // �洢�ռ����ʧ��
  ha = GetHead(La);      // ha��hb�ֱ�ָ��La��Lb��ͷ���
  hb = GetHead(Lb);
  pa = NextPos(La, ha);  // pa��pb�ֱ�ָ��La��Lb�е�ǰ���
  pb = NextPos(Lb, hb);
  while (pa && pb) {     // La��Lb���ǿ�
    a = GetCurElem(pa);  // a��bΪ�����е�ǰ�Ƚ�Ԫ��
    b = GetCurElem(pb);
    if ((*compare)(a, b)<=0) {  // a��b
      DelFirst(ha, q);  Append(Lc, q);  pa = NextPos(La, pa);  
    } else {   // a��b
      DelFirst(hb, q);  Append(Lc, q);  pb = NextPos(Lb, pb);  
    }
  } // while
  if (pa) Append(Lc, pa);        // ����La��ʣ����
  else Append(Lc, pb);           // ����Lb��ʣ����
  FreeNode(ha);   FreeNode(hb);  // �ͷ�La��Lb��ͷ���
  return OK;
} // MergeList_L
                               

