// yudaiyan.c ����� 
inherit NPC;
void create()
{
set_name("�����", ({ "yu daiyan", "yu" }));  
set("nickname","�䵱����");
    set("long", 
        "�����������������������ҡ�\n"
        "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
        "һ��Ӣˬ�������������͵�ģ����\n");
    set("gender", "����");
    set("age",43);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 18);
    set("int", 18);
    set("con", 18);
    set("dex", 18);
    
    set("max_qi", 20);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 50);
    set("combat_exp", 2000000);
    set("score", 60000);
    set_skill("force", 200);
    set_skill("taiji-shengong", 180);
    set_skill("dodge", 180);
    set_skill("tiyunzong", 160);
    set_skill("unarmed", 200);
    set_skill("taiji-quan", 200);
    set_skill("parry", 180);
    set_skill("sword", 180);
    set_skill("taiji-jian", 160);
    set_skill("literate", 150);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-quan");
    map_skill("sword", "taiji-jian");
    create_family("�䵱��", 2, "����");
    setup();
    carry_object("/d/wudang/obj/greyrobe")->wear();
    carry_object("/d/kunlun/obj/sandals")->wear();
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 100) {
        command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
        return;
    }
    command("say ���Ѿ��Ƿ���һ�������ܽ���ʲô���㻹�ǰ��ҵ�����ʦ�ְɣ�");
}
