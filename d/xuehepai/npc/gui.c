// made by lks

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "gui.h"
void heal_ob();
void recover_ob();

void create()
{
        set_name("������",({"gui wuyin","gui"}));
        set("nickname",HIR"Ѫ������"NOR);
	set("gender","����");
	set("int",30);	
	set("con",30);
	set("str",30);
	set("dex",30);
	set("bac",40);
	set("age",40);
	set("attitude","friendly");
        set("combat_exp",1200000);
        set("kill",1000);
	set("long",
"�Ǹ��ڳԵ��ˣ���ò��ª,���Բ��ݼ��ˡ�\n"
	);
        set("neili",5000);
        set("jingli",3000);
        set("max_neili",5000);
        set("max_jingli",3000);
        set_skill("literate",400);
        set_skill("cuff",400);
        set_skill("parry",400);
        set_skill("dodge",400);
        set_skill("youran-bu",400);
        set_skill("yudi-bian",400);
        set_skill("whip",400);
        set_skill("jieniu-dao",400);
        set_skill("blade",400);
       set_skill("yiqiguan-riyue",400);
        set_skill("throwing",400);
        set_skill("youren-jian",400);
        set_skill("sword",400);
        set_skill("tianhe-jian",400);
        set_skill("force",400);
        set_skill("taoism",400);
        set_skill("feixue-quan",400);
          map_skill("force","yiqiguan-riyue");
        map_skill("cuff","feixue-quan");
        map_skill("sword","tianhe-jian");
        map_skill("blade","jieniu-dao");
        map_skill("throwing","youren-jian");
        map_skill("whip","yudi-bian");
        prepare_skill("cuff","feixue-quan");
	
       create_family("Ѫ����",10,"����");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 2);
	set("chat_msg", ({
		(: heal_ob :),
	}));
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                  (: exert_function, "zhibiao" :),
                (: recover_ob :),
	}) );
}

	
void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

