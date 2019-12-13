inherit NPC;
inherit F_MASTER;
string ask_bo();
string ask_skill();
string ask_wang();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword(); 
string ask_book();
string ask_book2();
object ob = this_object();

void create()
{
        set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
        set("title","����Ľ�ݹ���");
        set("nick","�Ա�֮�� ��ʩ����");
        set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݸ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 27);
         set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("xyzx_sys/level", 1000);//2015.9�޸��������ż����npc��ǿ��
        set("max_qi", 123500);
        set("max_jing", 753000);
        set("neili", 3000500);
        set("max_neili", 1123500);
        set("jiali", 8000);
        set("combat_exp", 5000000);
        set("score", 50000);                

        set_skill("dodge",2280);
        set_skill("unarmed",2280);
        set_skill("force", 2270);
        set_skill("canhe-zhi", 1260);
        set_skill("murong-jianfa",1260);       
        set_skill("shenyuan-gong", 1260);
        set_skill("yanling-shenfa", 1260);   
        set_skill("xingyi-zhang", 1270);
        set_skill("douzhuan-xingyi", 1280);
        set_skill("parry", 2280);
        set_skill("sword", 2160);
        set_skill("literate", 2170);
        set_skill("murong-daofa", 1160);
        set_skill("blade",2160);
        
        map_skill("blade", "murong-daofa");
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("unarmed", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
        map_skill("sword", "murong-jianfa");
       
        create_family("����Ľ��",2,"����");

        set("inquiry", 
                ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n",
                        "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
                        "rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
                        "����" : "�ҵĹ���ס����٢��ɽׯ���������������µ������񶴡�\n",
                        "��ʩˮ��" : (: ask_ge :),
                        "Ľ�ݲ�" : (: ask_bo :),
                        "����" : (: ask_book :),
                        "������" : (: ask_wang :),
                        "����" : (: ask_sword :),
                        "��ת����"  : (: ask_skill :),
                        "��Ԫ��" : (: ask_dan :),
                        "��¶����ɢ" : (: ask_dan1 :),
                        "ͼ��" : (: ask_book2 :)
                ]));
        set("dan_count", 2);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 5);
        setup();
        
    carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 120) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

  command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
        command("chat* ����˵��������������һ���ģ������˸�ָ�տɴ�����");
        command("chat* haha"); 
        command("recruit " + ob->query("id"));
        ob->set("title","����Ľ�ݵ���������");
}

string ask_bo()
{
        mapping fam; 
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "�ȸ�ǰЩ����ͻȾ�񼲣��Ѿ������ˡ�\n";
         }

string ask_wang()
{
mapping fam;
        if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
        return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        return "�������ұ��ã�һֱ������ܵĺ��ϣ����Ҷ��ܳ�ʱ��û�м������ˡ�\n";
}

string ask_skill()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "��ת��������Ľ�ݼҵľ�ѧ������ע���мܺ�����\n";

}

string ask_ge()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "��ʩˮ������Ľ���ղ������ؼ�֮���ڣ����ҵ���.....\n";
}

string ask_sword()
{
mapping fam; 
        if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
                return "��������ү�����ź��������ð�������������úñ��ܣ�\n";
}

string ask_book()
{
        object ob;
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "Ľ�ݸ�")
        return RANK_D->query_respect(this_player()) + 
                "��������������̸������";

        if (  present("zi hua", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

        if (query("book_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

		if ((int)this_player()->query_skill("douzhuan-xingyi", 1) < 150)
                return RANK_D->query_respect(this_player()) + 
                "��������������̸������";

        ob = new("d/mr/obj/shu1");
        ob->move(this_player());

        add("book_count", -1);

        message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
        return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}

string ask_book2()
{
        object ob;
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (!(fam = this_player()->query("family")) || fam["master_name"] != "Ľ�ݸ�")
        return RANK_D->query_respect(this_player()) + 
                "��������������̸������";
        if (  present("tu jie", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

        if (query("book2_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

        ob = new("d/mr/obj/shu2");
        ob->move(this_player());

        add("book2_count", -1);

        message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
        return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}
 
string ask_dan()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

      if ( (int)this_player()->query("max_neili" ) < 400)
                return RANK_D->query_respect(this_player()) + 
                "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (  present("guiyuan dan", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";

        if (query("dan_count") < 1) return "�Բ��𣬹�Ԫ���Ѿ�������Ҫ���ˡ�";

ob = new("/d/mr/obj/guiyuan-dan");	
        ob->move(this_player());

        add("dan_count", -1);

        message_vision("$N���һ�Ź�Ԫ����\n",this_player());
        return "�ðɣ��˵�������������һ�������Ṧ���������Ҿʹ�����ɡ�";

}

string ask_dan1()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";

        if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(this_player()) + 
                "���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

        if ( (int)this_player()->query("max_neili" ) < 100)
                return RANK_D->query_respect(this_player()) + 
                "������������ҩ����к����ˣ�����ʱ�������ɡ�";

        if (  present("qingxin san", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";
        if (query("dan1_count") < 1) return "�Բ�����¶����ɢ�Ѿ�������";

        ob = new("d/mr/obj/qingxin-san");
        ob->move(this_player());

        add("dan1_count", -1);

        message_vision("$N���һ����¶����ɢ��\n",this_player());
        return "�ðɣ���ҩ������������һ�������Ṧ���������Ҿʹ�����ɡ�";

}
