void MSort(RedType SR[], RedType TR1[], int s, int t) { // �㷨10.13
   // ��SR[s..t]�鲢����ΪTR1[s..t]��
   int m;
   RedType TR2[20];
   if (s==t) TR1[t] = SR[s];
   else {
      m=(s+t)/2;            // ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]
      MSort(SR,TR2,s,m);    // �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m]
      MSort(SR,TR2,m+1,t);  // ��SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]
      Merge(TR2,TR1,s,m,t); // ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]
   }
} // MSort