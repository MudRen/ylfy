#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ʫʫ", ({ "li shishi","li","shishi" }) );
        set("title", HIR "���µ�һ����" NOR);
        set("gender", "Ů��" );
        set("age", 22);
        set("str", 10);
        set("per", 30);
        set("long", @LONG
�������ݷ�������ü��һ˫��ϲ��ϲ����Ŀ��
�ж����������磬�о��ƽ�����ˮ��
LONG
);
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
"��ʫʫ�������������ȹ������¶������˫������֬��ϸ�㣮\n",
"��ʫʫ�ƺ����ȣ�������������ȣ����ѩ�׼�ͦ�����ž����۵ף�\n",
"��ʫʫ����Ц��Ц���ּ���������������ǳ���\n",
        }) );

        setup();
        carry_object(__DIR__"obj/sskirt")->wear();
}

int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
}

int accept_object(object me, object ob)
{
        if ((string)me->query("gender")=="����"){
          if ( ob->query("money_id") && ob->value() >= 30000000 ) {
             command("blush");
             message_vision( HIM "$N�ԳԵ�Ц�ţ����$n���ۣ���λ" + RANK_D->query_respect(me) +"�����ǿ����˼�檣�\n" NOR, this_object(), me);
             me->set_temp("tmark/love2",1);
             command("follow "+(string)me->query("id"));
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
        if ( ob->query_temp("tmark/love2") ) {
           if( !ob || environment(ob) != environment() ) return 0;
           if ((string)ob->query("gender")=="����")
              command("makelove "+(string)ob->query("id"));
              command("follow none");
        return 1;
        } else return notify_fail( HIW "��ʫʫ����ش��˸���Ƿ��Ц������λ" + RANK_D->query_respect(ob) +"�����㻹����Щ�ؼ�ЪϢ�ɣ�\n" NOR );
}

