int fix_mfset(MFSet &S, int i) {  // �㷨6.11
   // ȷ��i�����Ӽ���������i����·�������н�㶼��ɸ��ĺ��ӽ�㡣
   int j,k,t;
   if (i<1 || i>S.n) return -1;       // i ����S����һ�Ӽ��ĳ�Ա
   for (j=i; S.nodes[j].parent>=0; j=S.nodes[j].parent) 
      printf("\t%d(%d%3d)\n", j, S.nodes[j].data, S.nodes[j].parent);
   for (k=i; k!=j; k=t) {
      t=S.nodes[k].parent;  S.nodes[k].parent=j;
   }
   return 1;
} // fix_mfset
                               