void init()
{ 
        add_action("do_zhuyao","zhuyao");
        add_action("do_fangdan","fangyao");
        add_action("do_liandan","liandan"); 
}

int do_zhuyao(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("��Ҫ��ʲô��������ҩ��\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("�����ϲ�û����������!\n");

	if(me->is_busy())
	return notify_fail("��������æ,��һ����˵��!\n");

    return do_yao(me, obj);
}

//�����ҩ�Ƿ���óɹ�
int do_yao(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
    me = this_player();
 
    if (me->query_temp("zhuyao"))
    return notify_fail("�Բ������Ѿ���"+me->query_temp("zhuyaoname")+"����ҩ��!\n");

    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhuyao")) {
    write("������������������ҩ!\n");
      return 1;
    }
    write(HIR"����"+ob->name()+HIR"����ҩ!\n"NOR);
    me->set_temp("zhuyao",ob->query("zhuyao"));
    me->set_temp("zhuyaoname",""+ob->name()+"");
    destruct(ob);
    return 1;
    }
}

//��鸱ҩ�Ƿ���óɹ�
int do_fangdan(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("��Ҫ��ʲôҩ��ȥ��\n");

    if( !me->query_temp("zhuyao"))
    return notify_fail("����Ҫ�ȷ���ҩ,Ҫ��Ȼ�������õ�!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("�����ϲ�û����������!\n");

    return do_dan(me, obj);

}

// ������ҩ���Ƿ�ɹ���һЩ�������ص���zjb_dan
int do_dan(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
  
    foreach ( ob in all_inventory(me)){
		if (ob->short(1)!=arg) continue;
		if (!ob->query("yao")) {
			write("��������������������ҩ!\n");
			return 1;
		}

		if (me->query_temp("danname/"+ob->query("id")+""))
		return notify_fail("���Ѿ���"+ob->name()+"�Ž�����¯��!\n");

		if (ob->query("random"))
		me->add_temp("liandan/random",ob->query("random"));

		me->set_temp("danname/"+ob->query("id")+"",1);

		///////////////////////////////////////////////////////
		me->add_temp("zjb_dan",1);  //������ҩ�ɹ��ĺ���ֵ������4,С��20�������������
		////////////////////////////////////////////////////////
		
		write(HIR"���"+ob->name()+HIR"�Ž�������¯!\n"NOR);
		destruct(ob);
		return 1;
    }
}

int do_liandan(string arg)
{
    int shoubi,tui,all,zhuyao,all2,zjb,liandan;
    object dan;
    object me = this_player();
    shoubi = me->query_temp("liandan/shoubi");
    tui = me->query_temp("liandan/tui");
    all = me->query_temp("liandan/all");
    all2 = me->query_temp("liandan/random");
    zhuyao = me->query_temp("zhuyao");
    zjb = me->query_temp("zjb_dan");
    liandan = me->query_skill("liandan-shu",1);

    if (!arg) return notify_fail("��Ҫ���ĸ�����ĵ���\n");

    if (!me->query_temp("liandan"))
    return notify_fail("��û�ŵ�,������ƨ!\n");


	// By zjb@ty ��������������ĳ���!    
    if (arg == "random") {
		me->add("combat_exp",1000);
		me->delete_temp("zhuyaoname");
		me->delete_temp("danname");
		
		// By zjb@ty �����Ķ��⽱��!
		me->improve_skill("liandan-shu", me->query_int(1)*300+random(100));
		me->add("combat_exp",zjb*1000+random(1000));
		me->add("potential",zjb*100+random(500));
		me->start_busy(5);
		write(HIR"����������ʱ��֪��������Ҳ������ȥ��!\n"NOR);

		//////////////////////////////////////////////////////////////////////////////////////////
		
		// ������ > 1500 ���ɵĵ�
		if ( liandan > 5000 && zjb > 15) {
			if ( zjb > 15 && zjb < 20 && all2 < 211 &&all2 > 100 && random(100000)>99995) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan11");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
			return notify_fail(BLINK HIR"�㾹Ȼ�����˿���ʹ�������Ļ��굤!!!\n"NOR);
			}
		}

		// ������ > 1200 ���ɵĵ�
		if ( liandan > 3000 && zjb > 12) {
			if ( zjb < 15 && zjb > 14 && all2 < 200 && all2 > 100 && random(1000)>990) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan19");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIC"�������˿�������ȫ���书�ļ��ܵ�!!!\n"NOR);
			}

			if ( zjb < 15 && zjb > 13 && all2 < 200 && all2 > 30 && random(1000)>960) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan12");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIB"�������˿���ʹ�˷��ϻ�ͯ���ɵ�!!!\n"NOR);
			}

			if ( zjb < 15 && zjb > 12 && all2 < 150 && all2 > 40 && random(1000)>950) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan6");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿���������������ı�����!!!\n"NOR);
			}

			if ( zjb < 15 && zjb > 12 && all2 < 150 && all2 > 40 && random(1000)>950) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan7");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿�������������������!!!\n"NOR);
			}

			if ( zjb < 15 && zjb > 12 && all2 < 150 && all2 > 40 && random(1000)>950) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan8");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿�������������ǵĸ��ǵ�!!!\n"NOR);
			}

			if ( zjb < 15 && zjb > 12 && all2 < 150 && all2 > 40 && random(1000)>950) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan9");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿��������������Ե����Ե�!!!\n"NOR);
			}


			if ( zjb < 15 && zjb > 12 && all2 < 150 && all2 > 40 && random(1000)>950) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan10");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿�������������ò�����յ�!!\n"NOR);
			}
		}


		// ������ > 900���ɵĵ�
		if ( liandan > 900 && zjb > 9) {
			if ( zjb < 12 && zjb > 9 && all2 < 150 && all2 > 30 && random(10)>8 && zhuyao >= 11 && zhuyao < 15) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan20");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿����ӻ����Ṧ�ľ�����!!!\n"NOR);
			}

			if ( zjb < 12 && zjb > 9 && all2 < 150 && all2 > 30 && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan21");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿����ӻ���ȭ�ŵ�������!!!\n"NOR);
			}

			if ( zjb < 12 && zjb > 9 && all2 < 150 && all2 > 50 && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan22");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿����Ӷ���д�ֵ�������!!!\n"NOR);
			}

			if ( zjb < 12 && zjb > 9 && all2 < 150 && all2 > 30 && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan17");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿����ӻ����ڹ���̫����!!!\n"NOR);
			}

		}
		
		// ������ > 600���ɵĵ�
		if ( liandan > 600 && zjb > 6) {
			if ( zjb < 9 && zjb > 6 && all2 < 100 && all2 > 10 && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan13");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIG"�������˿ɽ�ٶ��Ľⶾ��!!!\n"NOR);
			}

			if ( zjb < 9 && zjb > 6 && all2 < 100 && all2 > 10 && random(10)>3 && zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan14");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIG"�������˿����ӹ�������ս����!!!\n"NOR);
			}

			if ( zjb < 9 && zjb > 6 && all2 < 100 && all2 > 10 && random(10)>2 && zhuyao >= 1 && zhuyao < 5) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan16");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIB"�������˿�����������������!!!\n"NOR);
			}

			if ( zjb < 9 && zjb > 6 && all2 < 150 && all2 > 10 && random(10)>3 && zhuyao >= 1 && zhuyao < 5) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan18");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿����ӻ��������а����!!!\n"NOR);
			}

		}

		// ������ > 300���ɵĵ�
		if ( liandan > 300 && zjb > 3) {
			if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 &&random(10)>4 && zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan1");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIR"�������˿�ʹ�Լ�״̬�ָ�����Ѫ����!\n"NOR);
				}

			if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 30 && random(10)>4 && zhuyao >= 1 && zhuyao < 5) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan2");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIG"�������˿�ʹ�Լ�ʹ�Լ�����busy�ļ��絤\n"NOR);
				}



			if ( zjb < 6 && zjb > 2 && all2 < 100 && all2 > 20 && random(10)>4 && zhuyao >= 11 && zhuyao < 15) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan4");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIW"������������ʥҩ�󻹵�!\n"NOR);
				}

			if ( zjb < 6 && zjb > 3 && all2 < 100 && all2 > 20 && random(10)>4&& zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan5");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIW"�������˲���ʥҩ,����!!!\n"NOR);
				}

		}

		// ������ > 1���ɵĵ�
		if ( liandan > 1) {
			if ( zjb < 3 && zjb > 1 && all2 < 100 && all2 > 20 && zhuyao >= 21 && zhuyao < 25) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan3");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				return notify_fail(HIW"������������ʥҩ������!\n"NOR);
				}
			
			if ( zjb < 3 && all2 < 100  && all2 > 5 ) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/obj/jinchuang");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIY"�������������õĽ�ҩ!\n"NOR);
				
			}

			if ( zjb < 3 && all2 < 100 && all2 > 1 ) {
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/obj/yangjing");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"��"HIR"��¯��"HIC"��"NOR+":"+HIG" ��˵"HIM+me->name(1)+NOR HIG"�ڳ���ҩ��������һ���񵤣�\n"NOR,users());
				return notify_fail(HIY"���������ƾ��õ�������!\n"NOR);
			}

		}

		//////////////////////////////////////////////////////////////////////////////////////////

		me->delete_temp("liandan");
		me->delete_temp("zhuyao");
		me->delete_temp("zjb_dan");
		dan = new("/d/liandan/obj/chayao");
		dan->set("zhuren",""+me->query("id")+"");
		dan->move(me);

		return notify_fail(HIW"��˴�����ʧ��,����һ������ҩƷ!\n"NOR);
	}
}