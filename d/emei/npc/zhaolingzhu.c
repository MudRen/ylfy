// zhaolingzhu.c ������
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "zhao lingzhu", "zhao", "lingzhu"}));
        set("long",
           "����ĸߴ���òƽƽ�����书ȴ���׼ҵ�������Ϊ�����һ����\n");
        set("gender", "Ů��");
        set("age", 28);
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 23);
        set("dex", 20);

        set("qi", 400);
        set("max_qi", 400);
        set("jing", 350);
        set("max_jing", 360);
        set("neili", 450);
        set("max_neili", 450);

        set("combat_exp", 160000);
      
        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("parry", 95);
        set_skill("unarmed", 90);
        set_skill("jinding-zhang",90);
        set_skill("zhutian-bu",90);
        set_skill("linji-zhuang",90);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "jinding-zhang");
        map_skill("unarmed", "jinding-zhang");
        map_skill("force","linji-zhuang");  
        prepare_skill("unarmed", "jinding-zhang");
      
        create_family("������", 5,"����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
  }
#include "/kungfu/class/emei/sujia.h"
