// qiaofu.c �Է�

inherit NPC;

void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao","fu" }));
	set("long", 
		"һ�����׳�������ˡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "heroism");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 20);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);

	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
int accept_object(object who, object ob)
{
   object obn;
   obn = new("/d/emei/obj/gangcha");
   if ( who->query_temp("send_goupi") )
    return notify_fail("�Է������˵�ͷ����ʾ��л��\n");
   if ((string)ob->query("id") == "gou pi")
    {
     command("say ��ɽ�к���̫�أ�С�϶��������岻�ʣ��ҵ�"+RANK_D->query_respect(ob)+"�Ĺ�Ƥ,������ʱ�����ˡ�\n");
     command("say С�϶�����Ϊ���������аѸֲ������"+RANK_D->query_respect(ob)+"������֮�ðɡ�\n");
     obn->move(who);
     who->set_temp("send_goupi",1);
     return 1;
      }
     return 0;
}