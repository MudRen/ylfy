// Ů����

inherit NPC;
string *names = ({"��","ڤ","Ӱ","��","ظ","��","��","��","��",});
void create()
{
	set_name(names[random(sizeof(names))]+"��", ({ "dizi","nv dizi" }) );

	set("gender", "Ů��");
	set("age", 15+random(10));
	

	set("long","�����ִ���,���в�������,���Բ�Ϊ��֪��\n");
	create_family("������", 4, "����");
        set("chat_chance", 8);
        set("chat_msg", ({
                "��˵ʦ������ʱ���ڸ������еõ���һ�ѱ���,��֪��ʲô��!\n",
                (: random_move :), 
                "Сʦ�ò�֪���ֶ㵽��ȥ��,�������Ҳ���.\n",
                (: random_move :), 
                "�⼸���������˴�����,ʦ�������Ƕ������!\n",
                (: random_move :) 
        }) );

	set_skill("unarmed", 350);
	set_skill("force", 350);
	set_skill("parry", 350);
	set_skill("dodge", 350);
	
set_skill("bitao-shengong",340);
	set_skill("baihua-zhang", 345);
	set_skill("feixian-jian",355);

	map_skill("unarmed", "baihua-zhang");
	map_skill("parry", "feixian-jian");
map_skill("force", "bitao-shengong");
	
	
	set("combat_exp",5000000);
	set("score",1000);
	
	set("inquiry", ([
		"here" : "������Ǻ��ϰ�����ѽ,���Ȼ��֪��ô?",
	"��������":"��ʦ����,�����ھ���,Ҳ������!",
	]) );	

	setup();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/roujing_sword")->wield();
            add_money("silver",5);
}
