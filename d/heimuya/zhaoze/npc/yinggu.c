//yinggu.c
inherit NPC;

string ask_tu();
string ask_huang();

void create()
{
        set_name(MAG "����" NOR, ({"ying gu", "ying" }));
        set("title", HIW "�������" NOR);
        set("shen_type", 5);
        set("gender", "Ů��");
        set("per",48);
        set("long",
                "�������˳ƺ�����������á�\n");
        set("age", 42);
        set("attitude", "friendly");
        set("inquiry", ([
                "�ܲ�ͨ" : "��Ҫ���Ǹ��ĺ���\n",
          "����ͯ�ܲ�ͨ" : (: command("say ����ͯ?"),command("laugh ying gu") :),
                  "��ͼ" : (: ask_tu :),
                "�λ�ү" : (: ask_huang :),
                  "һ��" : (: ask_huang :),
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("qimen-wuxing", 250);
        set_skill("yiyang-zhi", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 1000);
        set_skill("force", 100);
        set_skill("kumu-shengong", 100);
        map_skill("force", "kumu-shengong");
        map_skill("unarmed", "yiyang-zhi");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
         carry_object("//clone/cloth/ma_cloth")->wear();
}

string ask_tu()
{
      object me;
      me = this_player();
      if ((int)me->query_temp("tmark/��2")) {
          me->set_temp("tmark/��2", 0);
          me->set_temp("tmark/��3", 1);
          return "����Ҫ��ͼ���ǾͰ���ɱ�˶λ�ү�ɣ�\n"; 
      }
}

string ask_huang()
{
      object me;
      me = this_player();
      if (!(int)me->query_temp("tmark/��3")) {
          return "����Ϊ���ͺ¿�Ҿ��ϲ������ˣ�"+me->name()+"�������ֺ��ң�������ͷ�����ҡ�\n";
      } else {  
          new(__DIR__"obj/hongjuan")->move(me);
          me->set_temp("tmark/��3", 0);
          me->set_temp("tmark/��", 1);
          message_vision("���ø���$Nһ�����־\n",me);   
          return "���������ɣ�";
      }                                               
}

void do_yidang(object ob)
{
    int p1, p2, p3, p4;
    object me=this_object();
	
    if (environment(ob)!=environment(me)) return;
    if ((int)ob->query_temp("tmark/��1")) {
    p1=random(5)+1;
    p2=random(5)+1;
    p3=random(5)+1;
    p4=random(5)+1;
    ob->set_temp("passwd",p1*1000+p2*100+p3*10+p4);
    message_vision("$N"+CYN+"����$n������Ⱔ"+CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
    "��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4)+"���ģ����ҹ�����\n"+NOR,me,ob);
    }
     ob->delete_temp("tmark/��1");
}
void init()
{
    ::init();
    call_out("do_yidang",5,this_player());
}
