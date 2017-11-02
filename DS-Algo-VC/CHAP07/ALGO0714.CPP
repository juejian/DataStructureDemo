Status CriticalPath(ALGraph G) {  // �㷨7.14
  // GΪ�����������G�ĸ���ؼ����
  Stack T;
  int a,j,k,el,ee,dut;
  char tag;
  ArcNode *p;
  if (!TopologicalOrder(G, T)) return ERROR;
  for(a=0; a<G.vexnum; a++)
    vl[a] = ve[G.vexnum-1];    // ��ʼ�������¼�����ٷ���ʱ��
  while (!StackEmpty(T))       // ������������������vlֵ
    for (Pop(T, j), p=G.vertices[j].firstarc;  p;  p=p->nextarc) {
      k=p->adjvex;  dut=p->info;     //dut<j,k>
      if (vl[k]-dut < vl[j]) vl[j] = vl[k]-dut;
    }
  for (j=0; j<G.vexnum; ++j)            // ��ee,el�͹ؼ��
    for (p=G.vertices[j].firstarc;  p;  p=p->nextarc) {
      k=p->adjvex;dut=p->info;   
      ee = ve[j];  el = vl[k]-dut;
      tag = (ee==el) ? '*' : ' ';
      printf(j, k, dut, ee, el, tag);   // ����ؼ��
    }
  return OK;
} // CriticalPath