//diefeng
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
        set_name("����", ( {"die feng","feng"} ) );
		create_family("�����",48, "����");
        set("long","����ɵ���ʮ�˴����ӡ�\n" );
        set("attitude", "peaceful");
        
		set("age", 35);
        set("gender", "Ů��");
		set("shen_type", 1);
		set("str", 38);
		set("int", 58);
		set("con", 68);
		set("dex", 48);
    
		set("max_qi", 1000);
		set("max_jing", 1000);
		set("neili", 16000);
		set("max_neili", 8000);
		set("jiali", 50);
		set("combat_exp", 2400000);
		set("score", 70000);

        set_skill("dodge", 150);
        set_skill("force", 240);
		set_skill("taoism", 100);
        set_skill("meinv-shenquan",100);
        set_skill("literate",100);
        set_skill("parry", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("dieyi-jianfa", 180);
        set_skill("wudie-xinjing", 150);
        set_skill("wudie-bu", 90);
        map_skill("force", "wudie-xinjing");
        map_skill("dodge", "wudie-bu");
        map_skill("parry", "dieyi-jianfa");
        map_skill("sword", "dieyi-jianfa");
        setup();

        carry_object("d/wudie/obj/dieyi")->wear();
        carry_object("d/wudie/obj/jian")->wield();

}

void attempt_apprentice(object ob)
{	
		if (ob->query("gender") != "Ů��"){
                command("say �����ˣ�������������");
                return 0;
        }

        if ((int)ob->query("per") < 25 ){ 
                command("say �������ɽֻ����ɫ��Ⱥ��Ů�ӣ�\n");
                return 0;
        }
	
     command("say �ðɣ��������㡣\n");
     command("recruit "+ob->query("id"));
}


