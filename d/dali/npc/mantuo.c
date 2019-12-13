// mantuo.c ����
//date һ��

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "man tuo", "man", "waiter" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long",
                "��λ�������æ��æ�룬�к������������Ŀ��ˡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("vendor_goods", ({
               "/clone/food/jitui",
               "/clone/food/jiudai",
               "/clone/food/baozi",
               "/clone/food/mian",
        }));
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
            && ob->query_skill("begging",1) > 60 ){
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }else { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_kill","kill");
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������棬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say("��������������������湻æ�ģ�����Խ��Խ�á�Ҫ������ֲ�����.\n");
                        break;
        
}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        say("\n���Ӵ��һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);
        
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->move("/d/dali/dbdajie1");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴�С����һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}


int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}