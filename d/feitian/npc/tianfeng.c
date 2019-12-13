#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
    set_name("���ʮ����", ({ "master tianfeng", "tianfeng", "master"}) );
    set("gender", "����" );
    set("age", 55);
    set("nickname", CYN "��������" NOR);
    set("long", "һ����ɫ���ƣ�Ũü��ȧ���������ߣ�������ɱ��������ϥ����ɽ��֮�ϣ��¾���¶�����㣬ȴ��һ˫�߳���ľ��ľ��˷���ǰ��ľ���Ͼ��ַ��ű����ʳ�����\n");
    create_family("����������", 5, "�Ҷ�");
    set("rank_nogen",1);
    set("ranks",({"����","����","����",RED"��ɲ"NOR,HIR"����"NOR}));
    set("rank_levels",({32000,512000,1536000,3456000 }));
    set("str", 550);
    set("dex", 550);
    set("con", 550);
    set("int", 550);
    set("per", 50);
    set("tianyu_1",1);
    set("jing", 2500000);
    set("max_jing", 2500000);        
    set("qi", 5520000);
    set("max_qi", 5520000);
    set("max_jingli", 520000);
    set("neili", 14000000);
    set("max_neili", 1400000);
    set("jingli", 1220000);
    set("jiali", 150000);
    set("combat_exp", 2100000000);
    set("xyzx_sys/level", 3500);   

    set_skill("dodge",3800);       
    set_skill("unarmed",3800);
    set_skill("parry",3800);
    set_skill("blade",3800);
    set_skill("wuxing-dun", 2200);
    set_skill("shayi", 2200);
    set_skill("aikido", 2200);
    set_skill("shayi-xinfa", 2200);
    set_skill("shiren-jianfa", 2800);
    set_skill("shiren-quanfa", 2080);
    set_skill("force",3900);
    set_skill("huoxinliu-jianfa", 2200);
    set_skill("xuanhualiu-quanfa", 2200);
    set_skill("ninjitsu", 2200);
    set_skill("ittouryu", 2200);
    set_skill("enmeiryu", 2200);
    set_skill("literate", 3200);

        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        map_skill("unarmed", "enmeiryu");
              
        create_family("����������", 5, "�Ҷ�");
         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.mukuha" :),
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :),  
                (: perform_action, "unarmed.chuyao" :), 
                (: perform_action, "unarmed.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                        "���ʮ������ب�Ų��������ɫ����ͻȻ�����������۵�һ���ȳ�����Ѫ��\n",
                                })  );
        set("inquiry",  ([
                "���" : "���ӡ������ӡ��������������\n",
                ])              ); 
        setup();
    carry_object(__DIR__"wucloth")->wear();
    carry_object(__DIR__"muji")->wear();
        carry_object(__DIR__"blackblade")->wield();
} 
void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="����������")
        {
                command("say ������ʱ����??\n");
          return 0;
        }
        if(ob->query("combat_exp")<1000000)
        {
                 command("say ���ʵս�����������Ҳ��ܴ����㹦��\n");
            return 0;
        }
       	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 200) {
		command("say ��Ļ���������̫���ˣ���δ��������Ķ������ѧϰ�ҵ��书�ء�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѻ���������������������ɣ�");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 200) {
		command("say ���ɱ���ķ�̫��,���¿��Ʋ���ɱ�⡣"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ�ɱ���ķ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 200) {
		command("say ��Ŀ��ֵ�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰѿ��ֵ�������������ɣ�");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 200) {
		command("say ������ж�̫�͡�"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�㻹�ǰ����ж�������������ɣ�");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 200)
    {
        command("say ����֮������ɱ�⡣");
        command("say " + RANK_D->query_respect(ob) +
            "���ɱ��̫���ˣ�");
        return;
    }
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"��һ������"HIR"����"NOR);
       ob->set("class", "yujianliu");
}