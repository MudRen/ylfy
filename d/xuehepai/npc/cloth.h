void init()
{
        object ob;
        object me=this_player();
        mapping fam=(mapping)me->query("family");
        
        if (interactive(me))
        {
                if (fam && fam["family_name"]=="Ѫ����")
                {
                        if (me->query("combat_exp")>40000 && me->query("combat_exp")< 100000)
                        {
                                if (me->query("asked")>=1)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"һ����Ѫ�£���֮����!");
                                command("say ���һ�����Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/xuehepai/obj/cloth2");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth2");
                                me->set("asked",1);
                                return;
                        }
                        
                        if (me->query("combat_exp")>100000 && me->query("combat_exp")< 300000)
                        {
                                if (me->query("asked")>=2)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"������Ѫ�£���֮����!");
                                command("say ����������Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/xuehepai/obj/cloth3");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth3");
                                 me->set("asked",2);
                                return;
                        }                
                        if (me->query("combat_exp")>300000 && me->query("combat_exp")< 500000)
                        {
                                if (me->query("asked")>=3)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"������Ѫ�£���֮����!");
                                command("say ����������Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/xuehepai/obj/cloth4");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth4");
                                me->set("asked",3);
                                return;
                        }                
                        if (me->query("combat_exp")>500000 && me->query("combat_exp")< 800000)
                        {
                                if (me->query("asked")>=4)
                                        return;
                                me->start_busy(3);
                                command("smile "+me->query("id"));
                                command("chat �����ڴ�����������"+me->query("name")+"�ĵ���Ѫ�£���֮����!");
                                command("say ����ĵ����Ѫ�����պã����������ڱ��ɵĵ�λ��");
                                ob=new("/d/xuehepai/obj/cloth5");
                                ob->move(me);
                                me->set("cloth","/d/xuehepai/obj/cloth5");
                                me->set("asked",4);
                                return;
                        }                
                }
        }
}

