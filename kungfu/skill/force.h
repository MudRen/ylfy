int valid_public(object me)
{
  mapping skl = me->query_skills();
  string *sk;
  int i;
  string skl_name = explode(__FILE__, "/")[<1][0..<3];

  if (!mapp(skl)) return 1;
  sk = keys(skl);
  i = sizeof(sk);
  while (i--) {
    if (sk[i] != skl_name && SKILL_D(sk[i])->valid_enable("force"))
      return notify_fail("�㲻ɢ��"+to_chinese(sk[i])
        +"���������ϰ"+to_chinese(skl_name)+"��\n");
  }
  return 1;
}

