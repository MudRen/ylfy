// mmnz.c

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skills.h"
#include "mmnz.h"
void create()
{
        set_name("����Ů��", ({ "mengmian nuzi", "mengmian", "nuzi" }) );
        set("gender", "Ů��");
        set("age", 25 );
        set("long", "һ���������ݵ�Ů�ӣ���Ȼ�����棬�����β��������͵�ɱ����\n");
        set("combat_exp", 50000);
        set("shen", -15000);
        set("attitude", "aggressive");
        set("age", 25 + random(3));      
        set("str", 20+random(5));
        set("int",20+random(5));  
        set("con",20+random(5)); 
        set("dex",20+random(5));
        set("per", 30);
        set("shen_type", -1);
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",800);
        set("max_neili",800);
        set("score", 5000);

        
        set_skill("force", 80); 
        set_skill("unarmed", 100); 
        set_skill("poyu-quan",random(200));         
		set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("yunv-shenfa", 200); 
        set_skill("taiji-shengong",random(200));        
		map_skill("dodge", "yunv-shenfa");
        map_skill("force", "taiji-shengong");         
		map_skill("unarmed", "poyu-quan"); 
        map_skill("parry", "poyu-quan");
        setup();

        carry_object("/d/gumu/obj/qun1")->wear();

}


