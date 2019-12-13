// xiaoer3.c �Ƶ�С��
// arnzh 97/1/24
inherit NPC;
inherit F_DEALER;
inherit SELL_SALT;                          // ��˽��
void create()
{
    set_name("��С��", ({
 "xiao er", "xiao", "waiter" }) );
    set("gender", "����" );
       set("icon","30001");
    set("age", 22);
    set("long",
        "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set_skill("unarmed",30);
        set_skill("dodge",30);
        set_skill("taiji-quan",20);
        map_skill("unarmed","taiji-quan");
        set("max_qi",400);
    set("combat_exp", 5000);
    set("attitude", "friendly");
    set("rank_info/respect", "С����");
    set("need_salt",2000);                  // ��Ҫ2000��˽��
    set("vendor_goods", ({
                "/clone/food/jitui",
                "/clone/food/baozi",
                "/clone/food/jiudai",
    }));
    setup();
}
void init()
{
    
    object ob; 
    mapping myfam; 
    ob = this_player();
    ::init();
    if( interactive(ob) && !is_fighting() ) {
        if ( (myfam = ob->query("family")) 
        && myfam["family_name"] == "ؤ��" 
        && ob->query_skill("begging",1) > 10 )
        {
            remove_call_out("saying");
            call_out("saying", 0, ob);
        }
        else
        {
 
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
        }
    }
    add_action("do_buy", "buy");
    add_action("do_list", "list");
    add_action("sell_salt", "sell");                            // ��˽��
}
void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
    switch( random(2) ) {
        case 0:
            say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
            break;
        case 1:
            say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                + "����������\n");
            break;
    }
}
void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
    remove_call_out("kicking");
    call_out("kicking", 1, ob);
    
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
    ob->move("/d/wudang/xuanwumen");
    message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
        "���˴�С�Ե���һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
void reset()
{
    set("need_salt",2000);                  // ��Ҫ2000��˽��
}
