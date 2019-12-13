
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("������", ({"chen yulin", "chen", "yulin"}));
        set("title", "ؤ��ɶ��ֶ����");
        set("nickname", "��������");
	set("gender", "����");
        set("age", 36);
	set("long", 
                "��������Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
		"��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

        set("qi", 600);
        set("max_qi", 600);
	set("jing", 100);
	set("max_jing", 100);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
	
        set("combat_exp", 120000);
        set("score", 4000);
	
        set_skill("force", 60);                         // �����ڹ�
        set_skill("huntian-qigong", 60);        // ��������
        set_skill("unarmed", 65);                       // ����ȭ��
        set_skill("xianglong-zhang", 60);       // ����ʮ����
        set_skill("dodge", 60);                         // ��������
        set_skill("xiaoyaoyou", 60);            // ��ң��
        set_skill("parry", 60);                         // �����м�
        set_skill("staff", 75);                         // ��������
        set_skill("begging", 50);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
        create_family("ؤ��", 19, "�ֶ����");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
		return;
	}
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
	"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
