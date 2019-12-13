// wen-tailai.c ��̩��
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_me();

void create()

{
    set_name("��̩��", ({ "wen tailai", "wen" }));
    set("nickname", HIM"������"NOR);
    set("long", 
                "���Ǻ컨����ĸ���̩����\n"
        "��һ����Ϊ�������ɫ������\n"
        "����ͺ�������ʮ���£����ʮ�ֻ��࣬˫�����ͻ�����������ϼ�.\n");
        set("gender", "����");
        create_family("�컨��", 2, "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1500);
        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 100);
        set("combat_exp",800000);
        set("score", 100000);

        set_skill("force", 180);
        set_skill("honghua-shengong", 180);
        set_skill("dodge", 180);
        set_skill("youlong-shenfa", 180);
        set_skill("unarmed", 180);
        set_skill("baihua-cuoquan", 200);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("luohua-jian", 180);
        set_skill("literate", 150);

        map_skill("force", "honghua-shengong");
        map_skill("dodge", "youlong-shenfa");
        map_skill("unarmed", "baihua-cuoquan");
        map_skill("parry", "luohua-jian");
        map_skill("sword", "luohua-jian");

    setup();

    carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
    {
        if ((int)ob->query("shen") < 5000)
    {
        command("say �Һ컨����ͽ����");
        command("say ��λ" + RANK_D->query_respect(ob) +
            "ƽʱ��Ҫ����һЩ��������֮�£�");
        return;
    }

       command("say �ã�����������˻��������������ˣ�");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "yishi")
                ob->set("class", "yishi");
}