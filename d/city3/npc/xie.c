//by mei

inherit NPC;

int ask_huolong();
string ask_hanyu();

void create()
{
        set_name("л����", ({ "xie changfeng" , "xie" }));
        set("str", 20);
        set("gender", "����");
        set("age", 46);
        set("long", "��ʵ����ֻ����ʮ���꣬���µ����ź������ĥ��ʹ����\n"+
                    "����������ʮ���ˡ�ÿ�������һ����������Ʒ�����һ\n"+
                    "��ʱ�����ǵ������ͻ�����һ˿���⣬һ˫����������ʯ��\n");
        set("inquiry", ([
                "����֮��" : "���������洫���������գ�������֪���᲻���������ʧ������\n",
                  "������" : (: ask_huolong :),
                "ǧ�꺮��" : (: ask_hanyu :),
        ]));

        set("combat_exp", 2500);
        set("attitude", "friendly");
  
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
int ask_huolong()
{
        object obj,ob = this_object();
        object me=this_player();
        
    if (present("huolong bian",me)){
        command("say ��λ"+RANK_D->query_respect(me)+"�����Ѿ��õ�����������");
        return 1;
    }
        if ( me->query("make_bian")){
            if (time() > me->query("make_bian")){
                message_vision("$N���������һ�������޽���$n��\n",ob,me);
                obj=new("/clone/weapon/huolong-bian");
                obj->move(me);
                me->delete("make_bian");
                return 1;
            }else{
                message_vision(CYN+"$N˵������Ļ����޻�û���ã���������ɡ�\n",ob);
                return 1;
            }
        }else
        message_vision("$N���ǵ�����ͻȻ����һ˿���⣬�����ˡ�ಡ���һ������������\n"+
                       "�����е���������ô֪���һ�������޵ģ�����ǧ�꺮���𣿡�\n", ob);
           return 1;   
}
string ask_hanyu()
{
        object ob = this_object();
        object me = this_player();
        
    if (present("huolong bian",me))
        return "��λ"+RANK_D->query_respect(me)+"�����Ѿ��õ�����������";
    message_vision("$N��Ȼ���������ϣ�̾����������ǧ�꺮������л�Ҳ�֪���˶����ˣ����ǵò�����������\n", ob);
    command("cry xie changfeng");
    return "��λ" + RANK_D->query_respect(me) + "���������ǧ�꺮��ȥ�����Ұɣ�";
}
int accept_object(object me, object ob)
{
    if (userp(ob))  return 0;
    if (present("huolong bian",me)) return 1;
        if ( ob->id("han yu") ) {
                message_vision("$N���ź��񣬼��������᲻ס����������������˵����\n"+
                               "��л��λ" + RANK_D->query_respect(me) + "�������ڼ��������ˡ�\n"+
                               "�����������޳��˺����⣬��Ҫѩ��˿�ͻ����\n", this_object(),me);
                me->set_temp("tmark/��1", 1);
                return 1;
        }
        if ( ob->id("rousisuo") && me->query_temp("tmark/��1")) {
                message_vision("$N���˿�$n�����Ĳ�˿�����˵�ͷ��˵�����ܺã��ܺã�\n",this_object(),me);
                me->set_temp("tmark/��2", 1);
        }
        if ( ob->id("huolong jin") && me->query_temp("tmark/��1")) {
                message_vision("$N���˿�$n�����Ļ�������˵�ͷ��˵�����ܺã��ܺã�\n",this_object(),me);
                me->set_temp("tmark/��3", 1);
        }
        if (me->query_temp("tmark/��1") && me->query_temp("tmark/��2") && me->query_temp("tmark/��3")){
                message_vision("$N����$n΢һ��򦣬˵�����ܺã���λ"+RANK_D->query_respect(me)+",�������ʱ����ȡ�ްɡ�\n",this_object(),me);
                me->delete_temp("tmark");
                me->set("make_bian",time()+86400);
        }
        return 1;
}

