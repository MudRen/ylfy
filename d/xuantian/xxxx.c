//li.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void greeting(object);
void init();
void create()
{
    set_name("�������", ({ "chen"}) );
    set("gender", "����" );
    set("age", 65);
    set("long", "�����������ˡ�\n");
    set("attitude", "friendly");
    set("max_qi", 600);
    set("qi",600);
    set("max_jing", 500);
    set("jing",500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali",30);
    set("combat_exp", 20);
    set("score", 20);
    create_family(HBBLU"�޽�ɽׯ"NOR,-3001,"��ɽ��ʦ");
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
     command("say �ðɣ��������㡣\n");
     command("recruit "+ob->query("id"));
     if((int)ob->query("combat_exp")<10000)
       command("say ���ȵ�����������������ͯ�ӱȻ����аɡ�\n");
     return;
}

