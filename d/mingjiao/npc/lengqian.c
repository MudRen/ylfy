// lengqian.c 
#include "/quest/quest.h"
inherit NPC;

void create()
{
        set_name("��ǫ", ({ "leng qian", "leng" }) );
        set("nickname", YEL "����" NOR);
	set("long", "����������������ɢ��֮һ��������������������û��һ�������ܶ�������۾���\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
        set("per", 20);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 50);
        set("combat_exp", 900000);
	set("score", 60000);

	set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 90);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("literate", 80);

        set_skill("shenghuo-jian", 90);
        set_skill("shenghuo-shengong", 80);
        set_skill("shenghuo-quan", 80);
        set_skill("qingyunwu", 90);
      
        map_skill("sword", "shenghuo-jian");
        map_skill("parry", "shenghuo-jian");
        map_skill("force", "shenghuo-shengong");
        map_skill("unarmed", "shenghuo-jian");
        map_skill("dodge", "qingyunwu");

        set("inquiry", ([
                "����": "������ʥ���ã����й��ڱ��̵�����������Ե��Ƕ�ȥ������\n",
                "��ʦ": "����ǫ����ϲ���徻������ϲ��ͽ�� \n",
                      ]) );

        create_family("����", 34, "��������");


	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
