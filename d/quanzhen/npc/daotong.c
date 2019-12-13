inherit NPC;
void consider();

void create()
{
	set_name("��ͯ", ({"dao tong"}));
	set("gender", "����");
	set("age", 16);
	set("long",
             "����һλ��С����ȫ��̳��ҵĵ�ͯ��\n");
	set("attitude", "peaceful");
	
	set("str", 21);
	set("int", 18);
	set("con", 21);
	set("dex", 18);

	set("chat_chance", 1);
	set("chat_msg", ({
		"��ͯ˵������ǰ���������С��Ů����ȫ��̣����ǴӶ�¥���ܵġ���\n",
//		(: random_move :),
	}));

	set("qi", 450);
	set("max_qi", 450);
	set("jing", 450);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	
	set("combat_exp", 500000);
	set("score", 3000);
 
	set_skill("force", 90);             // �����ڹ�
	set_skill("tiangang-zhengqi", 90);    //�������
	set_skill("unarmed", 80);           // ����ȭ��
	set_skill("kongming-quan", 80);    //����ȭ 
	set_skill("dodge",80);      	     // ��������
	set_skill("qixing-huanwei", 80);        //���ǻ�λ
	set_skill("parry", 80);             // �����м�
	set_skill("sword", 90);             // ��������
	set_skill("quanzhen-jianfa", 90);        //����� 
	set_skill("literate",70);           //����д��  
  
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongming-quan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "quanzhen-jianfa");
	map_skill("sword", "quanzhen-jianfa");

	create_family("ȫ���",4, "����");
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/obj/greenrobe")->wear();
}


