// jing.h
// create by host jan,8 1998

void attempt_apprentice(object ob)
{
     object me;
     me = this_player();

     if ((string)ob->query("gender") != "Ů��" )
      {
        command("say ����ô�ܹ�������Ϊͽ�أ�");
       return;
      }
     if ((int)ob->query("shen") < 0)
        {
        command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                 "�Ƿ����ò�����");
                return ;
        }
    if( (string)me->query("class")=="bonze" )
       {
             command("nod");
             command("recruit " + ob->query("id"));
       }
     
      else {

                command("say �����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ���������ܽ䡣\n");
            }

}
