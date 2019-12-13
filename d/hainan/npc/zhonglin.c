// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(YEL"����"NOR, ({ "zhongling", "girl", "dizi" }) );
	set("title", YEL"Сʦ��"NOR);
	set("gender", "Ů��" );
	set("age", 15);
	set("str", 27);
	set("cor", 30);
	set("cps", 27);
	set("int", 24);

	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 3);

	set("long",
		"��������ʦ̫��С��һ������.�˿������а�����һ������֦.
����ؿ�����.\n");
       set("combat_exp", 30000000);
	set("score", 2000);
create_family("������", 4, "����");
        set("chat_chance", 10);
        set("chat_msg", ({
        "����Ц�����س���:����,����Ͱ�...... ......��\n",
        "����������������е�����֦,���ﲻ֪�ں�Щʲô��\n",
        "�����ʯ���ϲ��˸�����,������������\n",

"����������:Ϊʲô��֥�鿪��,����������,÷��,����,����,����... ....��\n",
        "����һ�߲�ͣ�����Ÿ���ˮ��,һ�������ͷ��������������Ŀ�ˮ��\n",

"�������˵��:��֪��֪�����������ı�������Щ?\n",
        "���������:��֪���ǰѱ���������ô����\n",
        "���鿴��������:Ϊʲôÿ�춼���˴�����������,��ĺ���ô?\n",
        "�����������������������\n",
        "����˫�ֹ�ͷ,���˸�����:�����ˡ�\n",
        "ʦ��Ϊʲô��׼���ǵ��ٲ�������?\n",
        }));


	set_skill("unarmed", 420);
	set_skill("parry", 420);
	set_skill("dodge", 420);
	set_skill("sword", 420);
	set_skill("force", 420);
	set_skill("literate", 720);

set_skill("bitao-shengong",420);
	set_skill("feixian-jian", 420);
	set_skill("baihua-zhang", 420);
set_skill("qiongya-bufa",420);

	map_skill("unarmed", "baihua-zhang");
	map_skill("sword", "feixian-jian");
	map_skill("parry", "feixian-jian");
 map_skill("dodge", "qiongya-bufa");

	set("inquiry", ([
		"out" : "��˵��,�ں�Զ�ĵط�,�и��а���Ͱ͵���,���ҵ���һ������..... ...��",
		"�ٲ�" : "ʦ����׼������㵽��ȥ,Ҳ��֪��Ϊʲô��",
		"����" : "��˵ʦ�������ʱ��,�ڸ����ĺ����еõ���һ�ѱ�����",
		"name": "�ҵ����ֲ��������߱���,����!",
		"here": "�����������з��ֵ�һ��Сɽ��,��ɱ������˵��",
	]) );

	setup();
	carry_object("/d/hainan/obj/taoshuzhi")->wield();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/flowershoe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("age") > 20) 
	{	command("say ���Լ���û��ʦ��,��λ" + RANK_D->query_respect(ob) + ",�����������Ҹ�����!");
		return;
	}
	command("say ��������λ" + RANK_D->query_respect(ob) + "��ɲ�Ҫ���ߺ��\n");
	command("recruit " + ob->query("id") );
        command("say �´�Ҫ����,ֻҪ�������С����˵[֥�鿪��]����.\n");	
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xiake");
}
