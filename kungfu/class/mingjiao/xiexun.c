// XieXun.c
// pal 1997.05.09

#include "ansi.h"
int ask_jinmao(string str);
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void create()
{
    set_name("лѷ", ({"xie xun", "xie", "xun", }));
	set("long",
        "����һλ��Ŀ�ΰ�쳣�ĵ����ߣ���һ���ײ����ۡ�\n"
        "����ͷ�Ʒ����������ݣ���������һ�㣬ֻ����ֻ�۾�����������\n"
	);

	set("title",HIG "����" HIY "��ëʨ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
set("shen", 0);	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

set("max_qi", 350000);  	
set("max_jing", 350000);        	
set("max_jingli", 80000);        	
set("neili", 1500000);           	
set("max_neili", 30000);	
set("jiali", 300);	

set("combat_exp", 150000000);	
	set("score", 800000);

set_skill("force", 1200);	
set_skill("dodge", 1500);       	
set_skill("blade", 1500);       	
set_skill("wuhu-duanmendao", 1500);       	
set_skill("parry", 1200);	
set_skill("unarmed", 1300);	
set_skill("hunyuan-yiqi", 1200);	
set_skill("shaolin-shenfa", 1500);	
set_skill("qishang-quan", 1300);	
set_skill("jingang-quan", 1300);	
set_skill("literate", 300);	

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "qishang-quan");
map_skill("blade", "wuhu-duanmendao");     	
map_skill("parry", "qishang-quan");	

	prepare_skill("unarmed","qishang-quan");

set("chat_chance_combat", 100);	
	set("chat_msg_combat", ({
(: perform_action, "blade.duan" :),
(: perform_action, "unarmed.hunpofeiyang" :),
	}) );
set("inquiry", ([
"��ëʨ��" : "������ϯ������Ҳ������--лѷ��",
"name" : "лѷ�����ҡ�",
"����" : "��....����������������ɢ����Ҳ���Իظ����շ���ˡ�",
"���޼�" : "�������ҵ����ӣ���֪�������������ˡ�����������Ϣ��",
"������" : "��...��ƾ��Ҳ����������������⡣��Ҫ�õ��ȵÿ���лĳ������ͷ��",
"��ë": (: ask_jinmao :),
]) );
	setup();

carry_object("/clone/cloth/lingyun")->wear();           	
carry_object("/clone/weapon/tulong")->wield();	
carry_object("/clone/cloth/zixuan")->wear();	
}
int ask_jinmao(string arg)
{
object me;
object xie;
object jinmao;
xie=this_object();
me=this_player();
if (me->query("class")!="shizhe")        	
{
command("say ���뱾�ɺ��޹ϸ𣬲�֪�⻰�Ӻ�˵��");	
return 1;
}
else {
if (xie->query_temp("sign")) 	
{
command("say �������ˣ��������˰�����ȥ�ˡ�");
return 1;
}
else {
message_vision(CYN "�������������ӵ���Ϣ�ˣ�̫����.....лѷ�����شӻ����������ë���˸�$N \n" NOR,me);
jinmao=new("/d/mingjiao/npc/obj/jinmao");
jinmao->move(me);
xie->set_temp("sign",1);
return 1;
}
}
}
