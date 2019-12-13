// pal 1997.05.28
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_news();
int ask_meeting();
int hai_tu();
void create()
{
        set_name("��Ѷ", ({ "you xun", "you", "xun" }) );
        set("nickname", "��������");
        set("gender", "����" );
        set("age", 42);
        set("long",
                "������ר�Ŵ�̽��������Ϣ����Ѷ��\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("max_jing",500);
        set("max_qi",500);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        set("inquiry", ([
        "name" : "С�ľ�����Ѷ����֪��Ҫ������ʲô��",
        "ŷұ��"  : "���ʿ��԰�����������ŷұ��ү��ѽ����˵�����ڴ���ͽ�ܵ�����ȥ\n��ס�ˣ�����˵�����ڱ��¸����ˣ�Ҳ��֪��١�\n",
        "��˹��"  : "��˵��ʲô��ʲ��ʥʹ��",
          "��ͼ"  : (: hai_tu :),
          "����"  : "��˵����Ϊ����һ��ʲô��ͼ��",
        "news" : (: ask_news :),
        "meeting" : (: ask_meeting :),
        "����" : (: ask_news :),
        "������" : (: ask_meeting :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 5);
    carry_object("clone/cloth/cloth")->wear();
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
    if( !ob || (environment(ob) != environment()) ) return;
    command("hi "+ob->query("id"));
    say("��Ѷ���ҿ��˿���С��˵������λ" + RANK_D->query_respect(ob) + "������˵��ǰЩ����\n"
                 "��������Ĳ�˹��һ�����ͷ����ˡ�\n");
}
int ask_news()
{
    int rows;
    string temp;
    temp = read_file(__DIR__"news.txt", 2, 1);
    rows = atoi(temp);
    temp = read_file(__DIR__"news.txt", 3, rows);
    temp = "��Ѷ˵����\n"+temp+"\n";
    write(temp);
    return 1 ;
}
int ask_meeting()
{
    int rows;
    string temp;
    temp = read_file(__DIR__"meeting.txt", 2, 1);
    rows = atoi(temp);
    temp = read_file(__DIR__"meeting.txt", 3, rows);
    temp = "��Ѷ˵����\n"+temp+"\n";
    write(temp);
    return 1 ;
}
int hai_tu()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision("��Ѷ�������´�����$Nһ�£�ʲô����ͼ���㲻Ҫ���ˣ������Σ�յ�ѽ��\n"
                 "��Ѷ������һ�£��١��٣�����...�������һ�������ӣ�������Կ��ǡ�\n"
                 ,ob);
  ob->set_temp ("tmark/ͼ" , 1 );
  return 1;
}
int accept_object(object who, object ob)
{
    object myenv ;
    if ((int)who->query_temp("tmark/ͼ"))
    {
    if (ob->query("money_id") && ob->value() >= 1000000) {
        message_vision("��Ѷ��$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) +
        "��˿������ң�\n����Ҳ�͸������˰ɣ�\n" , who);
        command("whisper " +who->query("id")+ " �Ǻ�ͼ�������������\n");        
        this_player()->delete_temp("��ͼ" );
        myenv = environment (who) ;
        tell_room(myenv,
        "��Ѷ��������Ľ���Ц����ȥ���������������ҿɲ��ɡ�\n"
        "ֻ��ϧ�˺�һλ" + RANK_D->query_respect(who) +"���ٺ٣�������\n") ;
        return 1;
    }
    else { 
    message_vision("��ѶЦ�Ŷ�$N˵���޹�����»���������Լ����Űɣ�\n", who);
    return 0 ;
         }
    }
    return 0 ;    
}

