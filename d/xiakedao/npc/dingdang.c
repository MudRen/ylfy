// dingdang.c ����

inherit NPC;
string inquiry_yu();

void create()
{
        set_name("����", ({ "ding dang","ding"}) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "һ��ʮ�߰������Ů�����������ӣ�һ�Ź��������������ޡ�\n");
        set("shen_type", 1);
        set("combat_exp", 10000000);
        set("str", 180);
        set("dex", 220);
        set("con", 25);
        set("int", 35);
        set("per",30);
        set("attitude", "friendly");

        set("qi", 80000);
        set("max_qi", 80000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 200000);
        set("max_neili", 2000);
        set("jiali", 500);

        set_skill("force", 400);
        set_skill("unarmed", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("taiji-shengong", 400);
        set_skill("taiji-quan", 400);
        set_skill("tiyunzong", 500);

        map_skill("force","taiji-shenfong");
        map_skill("unarmed","taiji-quan");
        map_skill("parry","taiji-quan");
        map_skill("dodge","tiyunzong");
        set("chat_change",15);

        set("chat_msg",({
            "������߶��: Ҳ��֪���ҵ�����������ô���ˡ�\n",
            "��������Ĩ�˰����ᡣ\n",
            "����һ��ţ�˵��: ���У���Ҫ��Ħ���°��ҵ�����Ȼ�����\n",
            "����̾�˿�����˵��: Ҫ����������ͺ��ˡ�\n",
       }) );
       set("inquiry",([
           "ʯ����" : (: inquiry_yu :),
           "Ħ����" : "\n ǰ������ɽ�����ˣ���ҪС��ѽ���Ǹ���ͷ���书��ǿѽ��\n",
           "������" : "\n ��˵����ʯ�����������ҾͲ�֪���ˡ�\n",
       ]) );
       set_temp("shoupa",1);
       setup();
//       carry_object("/d/city2/obj/baojia")->wear();
       carry_object("/d/city2/obj/shouzhuo")->wear();
       carry_object("/d/city2/obj/yupei")->wear();
       add_money("gold", 1);
}

string inquiry_yu()
{
 object me=this_player();
 object obn;
 message_vision("����˵������λ"+ RANK_D->query_respect(me)+"���������ҵķ����\n"
         +"����ȥ����ѩɽ�ɱ�л�̿�ץȥ����������������Ҳ��֪�����ǻ����\n"
         , me );
 if(query_temp("shoupa")==0)
 {  message_vision("������˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���"
       +"��ȥĦ���¿����ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "�漱�ˣ�";
 }
   message_vision("������˵������λ"+ RANK_D->query_respect(me)+"����������"
       +"һ����������������֮��㿴���ҵ�����\n"
       +"��Ͱ��������������������׵ġ������ˡ�\n" , me);
   obn=new("/d/xiakedao/obj/shoupa");
   obn->move(me);
   set_temp("shoupa",0);
   return "�����ӻ����ó�һ��Ư���������������㡣\n";
}
