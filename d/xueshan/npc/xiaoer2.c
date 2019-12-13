// /d/xueshan/npc/xiaoer.c �Ƶ�С��
inherit NPC;
inherit F_DEALER;
inherit SELL_SALT;                          // ��˽��
void create()
{
    set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
    set("gender", "����" );
       set("icon","30001");
        set("age", 25);
    set("long",
        "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 150);
    set("attitude", "friendly");
    set("rank_info/respect", "С����");
    set("vendor_goods", ({
                "/d/xueshan/obj/niupidai",
                "/d/xueshan/obj/qingke-m",
    }));
    set("need_salt",2000);                  // ��Ҫ2000��˽��
    setup();
    carry_object("/clone/cloth/cloth")->wear();
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
                                + "�������ȱ����Ͳ�ɡ�\n");
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
        ob->move("/d/xueshan/tulu2");
    message("vision","ֻ����ƹ����һ����" +  ob->name() +
                "���˴ӿ͵���һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
