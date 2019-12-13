inherit NPC;
 
void create()
{
        set_name("������", ({ "yan ruofeng","yan","ruofeng" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
�������ǻ�ҩʦ��С�����Ĺ�Ů���ɻ�ҩʦ���̵ֽ���һ�����˳ƾ���
����ַ�������һ�������ʳ����������
TEXT
        );
        set("per", 30);
        set("class", "taohua");
        set("combat_exp", 10000);
        set_skill("unarmed",30);
        set_skill("luoying-zhang",30);
        set_skill("dodge", 30);
        set_skill("anying-fuxiang" , 30);
        set_skill("force",30);
        map_skill("dodge", "anying-fuxiang");
        map_skill("unarmed","luoying-zhang");   
        set("neili", 500);
        set("max_neili", 500);
        set("chat_chance", 7);
        set("chat_msg", ({
        "�����΢Ц��˵���������һ�����ɫ��������ӭ�����ͣ�\n",
        "�������˵�˵�����Ҽ���������ˣ�\n",
        "�����΢Ц��˵�����������������һ������������������µ�һѽ��\n",
        }) );
        create_family("�һ���", 3, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        object teatp,foodtp;
        if( !ob || environment(ob)!=environment() )
                return;
        if ( ob->query_temp("taohua/�跹") )
           say( "����΢Ц��˵�� ��λ" +
                RANK_D->query_respect(ob)+ "����ã���ӭ�����һ�����\n");
        else
        {       
                tell_room(environment(this_object()),
                        "������ϲ跹��΢Ц��˵����\n��λ" +
                        RANK_D->query_respect(ob)
                        + "����ã���ӭ�����һ��������÷���\n");
                teatp = new("/d/taohua/obj/cha");
                teatp ->move(ob);
                foodtp= new("/d/taohua/obj/gao");
                foodtp->move(ob);
                
                command ("say �������������ģ�����Ʒ����\n");
                ob->set_temp("taohua/�跹", 1); 
        }
}
