/*  <SecCrypt CPL V3R05>  */ 
inherit  NPC;

int  random2  (int  i)
{
    return  (random(i)+uptime())  %  i;
}

void  create()
{
    set_name("����",  ({  "dou ji",  "ji"  })  );
    set("race",  "Ұ��");
    set("gender",  "����");
    set("age",  2);
    set("no_die",1);
    set("long",  "һֻ������Ķ�����\n");
    set("attitude",  "friendly");
    set("max_qi",200+random2(2));
    set("qi",200+random2(2));
    set("max_jing",100+random2(2));
    set("jing",100+random2(2));
    set("str",  40+random2(2));
    set("int",  40+random2(2));
    set("con",  40+random2(2));
    set("dex",  40+random2(2));
    set_skill("unarmed",  random2(2)+10);
    set_skill("dodge",  random2(2)+10);
    set_skill("parry",  random2(2)+10);
    set("limbs",  ({  "ͷ��",  "����",  "β��"  })  );
    set("verbs",  ({  "bite"})  );
    
    set_temp("apply/attack", 1);
    setup();
}

