inherit NPC;
string inquiry_yu();
void accept_object(object me, object ob);

void create()
{
        set_name("���", ({ "yu fu" }) );
        set("gender", "����" );
        set("age", 22);
		set("no_get",1);
        create_family("���͵�", 2, "����");
       set("inquiry",([
          "���͵�" : (: inquiry_yu :),
          ]) );
        setup();
        
}
/*int accept_object(object me, object ob)
{
        object ling1;
        object ling2;

        return 1;

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("name"));
        ling1->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("name"));
        ling2->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        return 1;
}
*/
string inquiry_yu()
{
 object me=this_player();
 object ling1;
 object ling2;
 message_vision("���˵������λ"+ RANK_D->query_respect(me)+"����ȥ���͵���\n"
         +"�ɲ�����ѽ��ǧ��Ҫ������ȥ!����\n"
         , me );
 if(me->query("combat_exp") > 500000)
 {  message_vision("�����˵������λ"+ RANK_D->query_respect(me)+"���ҿ���"
       +"�ڽ�����Ҳ�Ǹ���������Ӣ�ۣ��Ҿͳ�ȫ�������Ը��!��\n",me);
       
        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);
        return "ף��һ·˳�硣\n";
 } 
  else   
  {     return "��λ"+ RANK_D->query_respect(me)+"�����ϵ���"
      +"�ҿ��㻹����Ŭ��Ŭ����\n";
  }
  
  }