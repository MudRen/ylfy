// mishu.c

inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
string ask_me();
int do_halt();
int do_no();

void create()
{
set_name("����������--Ů����", ({ "gaoshi mishu", "mishu", "mishu" }) );	
        set("gender", "Ů��");
        set("age", 25);
        set("no_get", 1);
        set("long",
                "����һλò�����ɵ�С�㣬���ǽ������Ƶ����飬һ�е�ҵ������������\n");
        set("combat_exp",60000);
        set("shen_type", 1);
        set("attitude", "friendly");

set("per", 27);	
        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        set("inquiry", ([
"��ɽ�۽�"       : (: ask_me :),	
        ]));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

if ( !wizardp(this_player()) ) return "����Ȩ�ٿ���ɽ�۽���\n";	

        for ( i=sizeof(ob); i>0; i-- ) {
                if (environment(ob[i-1]))
                {
ob[i-1]->move("/d/huashan/houzhiwangyu");                	

                }
        }

return "�ã���ɽ�۽���ʽ��Ļ��\n";	
}






