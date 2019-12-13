inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�˰ٴ�",({"deng baichuan","deng","baichuan"}));
        set("title","����ׯׯ��");
        set("long", 
              "�����ǹ���Ľ������ׯ��ׯ����\n");
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
        set("combat_exp", 600000);
        set("score", 35000);

        set_skill("unarmed",190);
        set_skill("dodge",190);
        set_skill("force", 180);
        set_skill("shenyuan-gong", 190);;
        set_skill("ding-dodge", 190);
        set_skill("parry", 190);
        set_skill("canhe-zhi", 190);
        set_skill("literate", 190);

        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "ding-dodge");
        map_skill("parry", "canhe-zhi");
        map_skill("unarmed", "canhe-zhi");       

            set("no_get",1);
        prepare_skill("unarmed","canhe-zhi");
        setup();
        carry_object("d/mr/obj/cloth2")->wear();        
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ������ׯׯ���˰ٴ���\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "����Ǭ" : "����Ǭ���Ҷ��ܣ����������ϼׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������ܣ�����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
       ]));                 
        set("chat_chance",20);
       set("chat_msg",({
                "�˰ٴ��������ﵽ�����ϻض���˹��ӵĹ�Ԫ����Ҫô�ĵܵ������Ͷ��ˡ���\n",
                "�˰ٴ���������ү��ǰ���Ӱ����Ǳ���Ҳһͬ�����ˡ�\n", 
                "�˰ٴ���������үȥ�������ҵ�ͷ��������ˡ�\n",
              
        }) );
}                                    

void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
                if( (string)ob->query("class") != "scholar")
                ob->set("class", "scholar");
        ob->set("title","����Ľ�ݵ��Ĵ�����");
}
