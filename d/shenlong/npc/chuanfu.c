// chuanfu.c �ϴ���
#include <ansi.h>
inherit NPC;
int  chu_hai();
void goto_dao(object ob);
void create()
{
        set_name("�ϴ���", ({ "lao chuanfu","chuanfu" }));
        set("gender", "����");
        set("age", 56);
        set("long",
        "����һ���ϴ��򡣱�����˪������͸��һ˿�ƻ�����������������ǰ����\n"
        "ȥ����������������ӵ��һ�Ҵ󴬿��Գ�����\n",
            );
        set("combat_exp", 1000000);
    set("eff_qi",2000);
    set("qi",2000);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 100);
        set_skill("force", 200);
        set_skill("unarmed", 400);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set("inquiry", ([
                
                "���ߵ�" : "���ߵ�����һ�����ˣ�ǧ����ȥ��\n",
                "������" : "���ߵ�����һ�����ˣ�ǧ����ȥ��\n",
                "����" :   (: chu_hai :),
        ]) );
        setup();
    carry_object("/clone/cloth/cloth")->wear();
 }
int chu_hai()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision("�ϴ����������´�����$Nһ�£�ʲô���������㲻Ҫ���ˣ���\n"
                 "�ϴ���������һ�£�����...�������һ�����ӣ�������Կ��ǡ�\n"
                 ,ob);
  ob->set_temp ("����" , 1 );
  return 1;
}
int accept_object(object who, object ob)
{
    object myenv ;
    if ((int)who->query_temp("tmark/��1")) {
       if ( (string) ob->query("id") =="card4" ) {
          message_vision("�ϴ����������ƿ��˿�����$N˵������Ȼ��������������ģ���˵�����к�ͼ��\n", who);
          who->set_temp("tmark/��1", 0);
          who->set_temp("tmark/��2", 1);       
          return 1;
          }
    }
    if ((int)who->query_temp("tmark/��2")) {
       if ( ob->id("yang pi")) {
          message_vision("$N����$n���ͷ���ã����ǳ����ɣ�\n", this_object(),who);
          if (!myenv=find_object("/d/heimuya/zhaoze/haichuan"))
              myenv=load_object("/d/heimuya/zhaoze/haichuan");
          who->move(myenv);
          this_object()->move(myenv);
        who->delete_temp("tmark");
        return 1;
        }
    }
    if (!(int)who->query_temp("����"))
    {
    message_vision("�ϴ���Ц�Ŷ�$N˵���޹�����»���������Լ����Űɣ�\n", who);
    return 0 ;
    }
    if (ob->query("money_id") && ob->value() >= 10000) {
        message_vision("�ϴ����$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) +
        "��˿������ң�\n����Ҳƴ�������ƴ�����������ӱ��ˣ�\n" , who);
        this_player()->delete_temp("����" );
        message_vision("�ϴ���һ���֣������������ᴬ��\n", who);
        message_vision("���ᴬ���$N���˴���һ������ê�����Ϳ����ˣ����ϴ���ȴû�ϴ�......\n", who);
        myenv = environment (who) ;
        who->move ("/d/shenlong/dahai");
        tell_room(myenv,
        "�ϴ��򿴴����ˣ���������Ľ���Ц�ˣ�ȥ�������������������ҿɲ��ɡ�\n"
        "ֻ��ϧ���Ǽ��������Ĵ���Ҫ���ǰ��˸��Ե��ˡ��ٺ٣�������\n") ;
        tell_object(who, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("goto_shenlong",10,who) ;
        return 1;
    }
    else  
    message_vision("�ϴ�����ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
    return 0;
}
void goto_shenlong (object ob)
{
        if( !ob || ob->is_ghost()) return;
   tell_object(ob , "������ͣ����һ��С���ߡ������´�����\n" ) ;
   ob->move ("/d/shenlong/haitan") ;
}

