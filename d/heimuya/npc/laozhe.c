//NPC:  laozhe.c
inherit NPC;
 
void create()
{
        set_name("����", ({ "lao zhe", "oldman" }) );
        set("gender", "����" );
        set("age", 70);
        set("long", "�����ͷ���麵�̳�������,�������ܺ������ϻ���?\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("rank_info/respect", "�ϴ�ү");
       set("inquiry", ([
                
                "��ľ��" : "��ľ������һ����Ů�����ѵĳ��˶�ħ�����ǧ����ȥ��\n",
               "����"   : "������,�ѵ��������Т��,������������Ϻõ��̲�,�Ҿ͸���һ������\n",
                "����"   : "����˵�Ķ��������Ϻ�ľ�µ�������,��ȥ���Ϻ��̲�,�ҵȲ�����...\n",   
        ]) );
        setup();
		carry_object("/clone/cloth/cloth")->wear();
}
 
void init()
{
        object ob;
 
        ::init();
        ob = this_player();
        if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���˼�ͷҲ����˵������λ" + RANK_D->query_respect(ob)
                                + "����Ҫ����,С��Ұ�ޡ�\n");
                        break;
                case 1:
                        say( "���˼Ҷ���˵��:��Ҳһ��������,�ͺ���һ��,������кðɡ�\n");
                        break;
        }
}
 
int accept_object(object who, object ob)
{ 
        if ( (string) ob->query("id")=="han yancao" )
        {
                tell_object(who, "��ͷ����˵:�ã��ã����Ǹ��ú��ӡ�\n");                
                message_vision("��ͷ���˵�ͷ��˵��������������ȥ�ɡ�\n" ,who);             
                new(__DIR__"obj/card4")->move(who);   
                return 1;
        } 
        return 0;
}

