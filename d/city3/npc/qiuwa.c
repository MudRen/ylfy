// bye mei
inherit NPC;
int hai_tu();
void create()
{
        set_name("����", ({ "qiu wa", "qiu", "waiter" }) );
        set("gender", "����" );
       set("icon","30001");
        set("age", 22);
        set("long",
                "��λ������Ц�����æ������λ��Ȼ���ߣ����Ǳ��˽������ޣ�������û�в����ˡ�\n");
        set("combat_exp", 100);
        set("inquiry", ([
          "��"  : (: hai_tu :),
        "������"  : (: hai_tu :),
        ]) );
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬�󶼹�������\n");
                        break;
                case 1:
                        say( "�����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����ӭ���٣�������������ܵ���\n");
                        break;
        }
}
int hai_tu()
{
     object who;
     who = this_player();
          message_vision("�����������´�����$Nһ�£������������ݣ����ԡ�\n"
                         "�����ƹ�ķԸ������ˣ�ʮ�����ӣ��ٺ٣�\n",who);
          who->set_temp("tmark/��", 1);
      return 1;
}
int accept_object(object who, object ob)
{        
        if ( who->query_temp("tmark/��") ) {
           if (ob->query("money_id") && ob->value() >= 1000) {
                tell_object(who, "����һ������˵������л���ϣ��͹��뵽��Ժ��\n");
                who->move("/d/city3/houyuan.c");
                who->delete_temp("tmark/��");
                return 1;

                } else { 
                  message_vision("���޲��ͷ��ض�$N˵��С�Ķ�˵��Ҫʮ�����ӵ��ˣ��͹�û�������\n", who);
                return 0;
                }
        }
        if (ob->query("money_id") && ob->value() >= 50000) {
                tell_object(who, "����һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}

