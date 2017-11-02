void get_nextval(SString T, int *next) {  // �㷨4.8
  // ��ģʽ��T��next��������ֵ����������nextval��
  int i = 1;
  int j = 0;
  next[1] = 0;
  while (i<T[0]) {
    if (j==0 || T[i]==T[j]) {
      ++i;  ++j;
      if (T[i]!=T[j]) next[i] = j;
      else next[i] = next[j];
    }
    else j = next[j];
  }
} // get_nextval

int Index_KMP(SString S, SString T, int pos) {  // �㷨4.6
  // ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ��
  // ��KMP�㷨�����У�T�ǿգ�1��pos��StrLength(S)��
  int next[255];
  int i = pos;
  int j = 1;
  get_nextval(T, next);
  while (i<=S[0] && j<=T[0]) {
    if (j==0 || S[i]==T[j]) { ++i;  ++j; }  // �����ȽϺ���ַ�
    else j = next[j];                       // ģʽ�������ƶ�
  }
  if (j>T[0]) return i-T[0];            // ƥ��ɹ�
  else return 0;
} // Index_KMP
