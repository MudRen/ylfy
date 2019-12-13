// Npc: /kungfu/class/shaolin/qing-wei.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��Ϊ����", ({
        "qingwei biqiu",
        "qingwei",
        "biqiu",
    }));
    set("long",
        "����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
        "�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
    );
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 30);
    set("str", 23);
    set("int", 19);
    set("con", 22);
    set("dex", 20);
    set("max_qi", 1350);
    set("max_jing", 1200);
    set("neili", 1350);
    set("max_neili", 350);
    set("jiali", 30);
    set("combat_exp", 5000);
    set("score", 100);
    set_skill("force", 30);
    set_skill("hunyuan-yiqi", 30);
    set_skill("dodge", 30);
    set_skill("shaolin-shenfa", 30);
    set_skill("unarmed", 30);
    set_skill("banruo-zhang", 30);
    set_skill("parry", 30);
    set_skill("buddhism", 30);
    set_skill("literate", 30);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
    map_skill("parry", "banruo-zhang");
    
    create_family("������", 40, "����");
    setup();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}
void attempt_apprentice(object ob)
{
    object me  = this_object();
    mapping ob_fam = ob->query("family");
    mapping my_fam = me->query("family");
    if( (string)ob->query("gender") != "����" )
    {
        command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
        return;
    }
    
    if (mapp(ob_fam))
    if ( ob_fam["family_name"] == "������" && (ob_fam["generation"] <= my_fam["generation"]) )
    {
        command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
        return;
    }
    if( (string)ob->query("class")!="bonze" )
    {
        command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
    }
    command("say �����ӷ����գ����գ�");
    command("recruit " + ob->query("id"));
}
