// jingdao.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("����", ({ "jing dao","jing","dao"}));
        set("long",
      "����һλ������ҵ��ã����ڸ�£����ü��Ŀ��\n");

        set("gender", "Ů��");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 26);
        set("int", 22);
        set("con", 26);
        set("dex", 22);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);

        set("combat_exp", 4400000);
        set("score", 70000);

        set_skill("force", 175);
        set_skill("dodge", 175);
        set_skill("parry", 180);
        set_skill("unarmed", 185);
        set_skill("linji-zhuang",180);
        set_skill("zhutian-bu",180);
        set_skill("jinding-zhang",190);
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "jinding-zhang");
        map_skill("unarmed", "jinding-zhang");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "jinding-zhang");

        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
  }
