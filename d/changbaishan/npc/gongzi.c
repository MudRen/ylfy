
inherit NPC;

void create()
{
  set_name("����", ({"gong zi","zi"}));
  set("long","����һλ���ӡ�\n");
  set("gender", "����");
  set("combat_exp",80000);

  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  
  setup();
    carry_object("clone/cloth/cloth")->wear();
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob||is_fighting()) return;
   
   remove_call_out("welcome");
   call_out("welcome",1,ob);
   
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say ������ɽ�ľ�ɫ���֮�������ҿ�Ҫ��ʫһ���ˡ�������");
     break;
    case 1:
     command("say �羰�����������ϧ����û�м�����鰡��");
   }
   
}
