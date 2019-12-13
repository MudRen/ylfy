// Npc: /kungfu/class/shaolin/xuan-tong.c
// Date: YZC 96/01/19
inherit NPC;
void create()
{
    set_name("��ʹ��ʦ", ({
        "xuantong dashi",
        "xuantong",
        "dashi",
    }));
    set("long",
        "����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ĸߴ�\n"
        "���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
    );
    set("nickname", "����Ժ����");
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 70);
    set("str", 30);
    set("int", 50);
    set("con", 30);
    set("dex", 130);
    set("max_qi", 3500);
    set("max_jing", 1500);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 150);
    set("combat_exp", 1400000);
//before the modification, all the skills are 140
    set_skill("force", 210);
    set_skill("hunyuan-yiqi", 240);
    set_skill("dodge", 240);
    set_skill("shaolin-shenfa", 240);
    set_skill("parry", 240);
    set_skill("unarmed", 240);
    set_skill("club", 210);
    set_skill("staff", 240);
    set_skill("zui-gun", 200);
    set_skill("pudu-zhang", 240);
    set_skill("qianye-shou", 240);
    set_skill("yingzhua-gong", 240);
    set_skill("buddhism", 240);
    set_skill("literate", 240);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "yingzhua-gong");
    map_skill("staff", "pudu-zhang");
    map_skill("club", "zui-gun");
    map_skill("parry", "yingzhua-gong");
    create_family("������", 36, "����");
    set("chat_chance_combat", 45);
    set("chat_msg_combat", ({
        (: perform_action, "finger.fuxue" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void attempt_apprentice(object ob)
{
    object me; 
    mapping ob_fam, my_fam;

    string name;
    me = this_object();
    my_fam  = me->query("family");
    name = ob->query("name");
    if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
    {
        command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
        return;
    }
    if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
    {
        command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
        return;
    }
    if ( ob_fam["generation"] <= my_fam["generation"] )
    {
        command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
        return;
    }
    if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
    {
        command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
        command("recruit " + ob->query("id"));
    }
    else
    {
        command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
        return;
    }
    return;
}
