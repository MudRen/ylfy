// robber.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����ǿ��", ({ "mask robber" }) );
        set("long","����һ������ǿ�������Ӻ����ء�\n");
        set("attitude", "heroism");
        set("str", 20 + random(11));            // ����         
        set("per", 20 + random(11));            // ��ò
        set("int", 20 + random(11));            // ����         
        set("con", 20 + random(11));            // ����
        set("dex", 100 + random(11));            // ��         
        set("kar", 20 + random(11));            // ��Ե
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                BOLD "����ǿ���ȵ���߾����·���ҿ������������ԣ�Ҫ��Ӵ˹���������������\n" NOR,
                CYN "����ǿ���ȵ��������¶���������һ����·��\n" NOR,
                CYN "����ǿ���ȵ������ӿ�����ҪǮ����Ҫ����\n"NOR ,
                BOLD "����ǿ���ȵ���ǮҲҪ����ҲҪ��\n"NOR,
        }) );
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("shen", -10);
     set("demogorgon",1);
        set("no_suck",1);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        set_temp("apply/dodge", 40);
        setup();
        carry_object("/clone/cloth/hanbing-jia")->wear();
        carry_object("/clone/weapon/hanbing-dao")->wield();
        add_money("silver", 20);
}
void init()
{       
    object me,ob;
    int n;
    me=this_object();
    ob=this_player();
    ::init();
    if (present("biao yin",ob)){
        if (!me->is_killing(ob)){
                command("say "+ob->name()+"�����������£�������·����\n");
                set_leader(ob);
                command("kill "+ob->query("id") );
                n = ob->query("combat_exp") + random(10000) - 7000;
                if( n <= 0 ) n = random(3000) + 1;
				if( n > 50000000 ) n = 50000000;
                    set("combat_exp", n );
                n = ob->query_skill("force", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("force", n );
                n = ob->query_skill("unarmed", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("unarmed", n );
                n = ob->query_skill("force", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("blade", n ); 
                n = ob->query_skill("parry", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("parry", n );
                n = ob->query_skill("dodge", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("dodge", n );
                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("taiji-shengong", n );
                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("taiji-dao", n );
                n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("tiyunzong", n );
                map_skill("dodge", "tiyunzong");
                map_skill("force", "taiji-shengong");
                map_skill("blade", "taiji-dao");
                map_skill("parry", "taiji-dao");
        }
    }else   if (me->is_killing(ob) ){
            me->remove_killer(ob);
            me->set_leader(0);
    }
    if (living(ob))
   add_action("do_go","go");
}

int do_go(string arg)
{
	mapping exit;
	if (!environment()) return 1;
	if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
		return 0;
	if (is_killing(this_player()))
		if (random(10)>8) {
			message_vision(YEL "$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ��ȷ���������\n"NOR, this_player(), this_object());
			return 1;
	}
	return 0;
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
void leave()
{
       if (!environment()) return;
        message("vision",HIB + name() + "����ææ���߿��ˡ�\n" NOR, environment(), this_object() );
        destruct(this_object());
}
