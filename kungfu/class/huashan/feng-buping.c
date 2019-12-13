// feng-buping.c  封不平
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("封不平", ({ "feng buping", "feng" }) );
        set("nickname", YEL"狂风快剑"NOR);
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 45);
        set("long", "封不平是华山剑宗第一高手，满脸戾气一张黄焦焦的面皮。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400000);
        set("max_neili", 840000);
        set("jiali", 3000);
        set("max_qi",1200000);
        set("max_jing",720000);
		set("xyzx_sys/level", 1500);
        set("combat_exp", 1000000);
        set("shen", -200000);
		
        set("apprentice_available", 3);
        set_skill("unarmed", 2180);
        set_skill("sword", 2160);
        set_skill("force", 2160);
        set_skill("parry", 2160);
        set_skill("dodge", 2160);
        set_skill("literate", 100);
        set_skill("kuangfeng-jian", 1100);
        set_skill("zixia-shengong", 1160);
        set_skill("huashan-zhangfa", 1200);
        set_skill("huashan-shenfa", 1200);

        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("华山派", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 老夫今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say 我华山派以剑法为主，依我看"+RANK_D->query_respect(ob)+"不适合于学剑法。");
        else {
                command("say 好，好，好，很好。");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", "华山剑宗第十四代弟子");
        add("apprentice_availavble", -1);
}
void reset()
{
        set("apprentice_available", 3);
}

