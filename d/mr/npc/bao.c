inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����ͬ",({"bao butong","bao","butong"}));
        set("title","���ׯׯ��");
        set("nickname","��������");
        set("long", 
              "������Ľ�ݸ��Ľ���ֵܹ���Ľ�ݽ��ׯ��ׯ����\n");
        set("age", 25);
         set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 0);
        set("combat_exp", 500000);
        set("score", 35000);

        set_skill("sword",180);
        set_skill("blade",180);
        set_skill("dodge",180);
        set_skill("force", 180);
        set_skill("shenyuan-gong", 170);;
        set_skill("ding-dodge", 190);
        set_skill("parry", 180);
        set_skill("murong-daofa", 180);
        set_skill("literate", 180);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "ding-dodge");
        map_skill("parry", "murong-daofa");
        map_skill("blade", "murong-daofa");   

            set("no_get",1);
        setup();
        
        carry_object("d/mr/obj/cloth2")->wear();
        carry_object("clone/weapon/blade")->wield();   
        
        create_family("����Ľ��",3,"����");
        
        set("inquiry", ([
            "name" : "��Ҳ����Ҳ���Ҿ��ǹ���Ľ�ݽ��ׯׯׯ������ͬ��\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
            "����Ǭ" : "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
       ]));
}       
void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "scholar")
                ob->set("class", "scholar");
        ob->set("title","����Ľ�ݵ��Ĵ�����");
}
