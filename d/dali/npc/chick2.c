#include <ansi.h>
inherit NPC;
int doing(object me);
void create()
{
        set_name("����", ({ "girl" }) );
        set("title", HIM "����֮��" NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("str", 10);
        set("per", 30);
        set("long", @LONG
���������񷻵����ˣ���������Ȥ�Ļ����루����������
LONG
);
        set("combat_exp", 10);
        set("attitude", "friendly");

        setup();
        carry_object("clone/cloth/pink_cloth")->wear();
}

int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
}
int accept_object(object me, object ob)
{
        if ((string)me->query("gender")=="����"){
          if ( ob->query("money_id") && ob->value() >= 10000000 ) {
             command("blush");
             message_vision( HIM "$N�����ص���ͷ�����$n���ۣ���λ" + RANK_D->query_respect(me) +"�����ڴ˶�ҹ��\n" NOR, this_object(), me);
             me->set_temp("tmark/love",1);
             return 1;
             }
        }
        if ( ob->query("money_id") ) {
             command("smile");
             command("say ��л��λ" + RANK_D->query_respect(me) +"����һ�����������Ŀ��ĵģ�");
        return 1;
        } else { 
             command("say ��λ" + RANK_D->query_respect(me) +"�����Щʲô�������Ұ���");
        return 0;
        }
}

void init()
{
        ::init();
/*
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
*/
        add_action("do_enjoy","enjoy");
}

/*
int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
*/

int do_enjoy(object ob)
{
        ob=this_player();
        if ( ob->query_temp("tmark/love") ) {
           if( !ob || environment(ob) != environment() ) return 0;
           if ((string)ob->query("gender")=="����")
              command("makelove "+(string)ob->query("id"));
        return 1;
        } else return notify_fail( HIW "��������ش��˸���Ƿ��Ц������λ" + RANK_D->query_respect(ob) +"�����㻹�����ؼ�ЪϢ�ɣ�\n" NOR );
}

