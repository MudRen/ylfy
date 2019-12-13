// feng-buping.c  �ⲻƽ
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("�ⲻƽ", ({ "feng buping", "feng" }) );
        set("nickname", YEL"���콣"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 45);
        set("long", "�ⲻƽ�ǻ�ɽ���ڵ�һ���֣���������һ�Żƽ�������Ƥ��\n");
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

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say �һ�ɽ���Խ���Ϊ�������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
        else {
                command("say �ã��ã��ã��ܺá�");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", "��ɽ���ڵ�ʮ�Ĵ�����");
        add("apprentice_availavble", -1);
}
void reset()
{
        set("apprentice_available", 3);
}

