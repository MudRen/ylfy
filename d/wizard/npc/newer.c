// newer.c
inherit NPC;
void create()
{
set_name("���ŷ���ʹ",({ "newer" }) );	
set("gender", "����" );
set("age", 15);
set("long", 	CYN"����Ϧ������֮������������ŷ���ʹ�ߣ��������֪ͨ������������\n");
set("max_qi", 5000000);
set("max_jing", 5000000);
set("combat_exp", 5000);
set("shen", 0);
set("str", 24);
set("dex", 23);
set("con", 20);
set("per", 30);
set("int", 24);
set("attitude", "friendly");
set("chat_chance", 1);                                            	
set("chat_msg", ({
(: command, "xyxw �º����ߵ�����������ȡ����look table��pick gift��chai gift���������ͨ��help��ѯ��" :),       	
(: command, "xyxw �����Խ����и���������(���׽�)��fly yz;w;n;w;n" :),              	
(: command, "xyxw Ǯׯ�������һ���������߽�Ʊ��������50��" :), 
}) );
setup();
carry_object("/clone/cloth/cloth")->wear();
add_money("gold",100);	
}
void die()
{
message_vision("��Ǹ�����ǲ������ġ�\n",this_object());
return ;
}
