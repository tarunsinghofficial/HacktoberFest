<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0">
        <meta name="description" content="Smarthr - Bootstrap Admin Template">
		<meta name="keywords" content="admin, estimates, bootstrap, business, corporate, creative, management, minimal, modern, accounts, invoice, html5, responsive, CRM, Projects">
        <meta name="author" content="Dreamguys - Bootstrap Admin Template">
        <meta name="robots" content="noindex, nofollow">
        <title><?=$PageTitle;?> - <?=SITE_NAME;?></title>
		
<?php $this->load->view('User/inc/stylesheet');?>
    </head>
	
    <body>
		<!-- Main Wrapper -->
        <div class="main-wrapper">
        	
<?php $this->load->view('User/inc/header');?>
<?php $this->load->view('User/inc/sidebar');?>
			
			<!-- Page Wrapper -->
            <div class="page-wrapper">
			
				<!-- Page Content -->
                <div class="content container-fluid">
				
					<!-- Page Header -->
					<div class="page-header">
						<div class="row align-items-center">
							<div class="col">
								<h3 class="page-title">Order</h3>
								<ul class="breadcrumb">
									<li class="breadcrumb-item"><a href="<?=base_url('dashboard')?>">Dashboard</a></li>
									<li class="breadcrumb-item active"><?=$PageName;?></li>
								</ul>
							</div>
							<div class="col-auto float-right ml-auto">
								<!-- <a href="#" class="btn add-btn" data-toggle="modal" data-target="#add_address"><i class="fa fa-plus"></i> Add Delivery Address</a> -->
								<a href="#" class="btn add-btn" data-toggle="modal" data-target="#add_address"><i class="fa fa-plus"></i> Add Pickup Address</a>
								<div class="view-icons d-none">
									<a href="employees.html" class="grid-view btn btn-link active"><i class="fa fa-th"></i></a>
									<a href="employees-list.html" class="list-view btn btn-link"><i class="fa fa-bars"></i></a>
								</div>
							</div>
						</div>
					</div>
					<!-- /Page Header -->
					
					<!-- Search Filter -->
					<?=form_open('add-order-submit', 'class="get-pin mt-2" id="get-pin" name="get-pin"');?>
						<?php echo notification_message(); //dd($address);?>
					<div class="row filter-row">
						<div class="col-md-12">
							<div class="card">
								<div class="card-body">
									<h4 class="card-title">Shipment details</h4>
						<div class="row">
							<div class="col-sm-6 col-md-3"> 
								<div class="form-group form-focus select-focus">
									<select class="select floating" name="uo_upa_FK_id" required> 
										<option value="">Choose One</option>
										<?php if($address): 
											  foreach($address as $address):?>
										<option value="<?=$address->upa_id;?>"><?=$address->upa_address;?></option>
										<?php
											endforeach; 
											endif; ?>
									</select>
									<label class="focus-label">Address</label>
								</div>
							</div>
							<div class="col-sm-6 col-md-3">  
								<div class="form-group form-focus">
									<input type="text" name="uo_drop_pin" class="form-control floating" required>
									<label class="focus-label">Drop pin</label>
								</div>
							</div>
							<!--  -->
										</div>
					            </div>
					        </div>
					    </div>
					</div>

					<div class="row">
						<div class="col-md-12">
							<div class="card">
								<div class="card-body">
									<h4 class="card-title">Package Details</h4>
									<div class="row">
										<div class="col-md-3">
											<div class="form-group">
												<label>Product Name</label>
												<input type="text" name="uo_package_name" class="form-control" required>
											</div>
										</div>
										<div class="col-md-3">
											<div class="form-group">
												<label>Quantity</label>
												<input type="text" name="uo_quantity" class="form-control" required>
											</div>
										</div>
										<div class="col-md-3">
											<div class="form-group">
												<label>Unit Price</label>
												<input type="text" name="uo_price" class="form-control" required>
											</div>
										</div>
										<div class="col-md-3">
											<div class="form-group">
												<label>Total Price</label>
												<input type="text" name="uo_total_price" class="form-control" required>
											</div>
										</div>
									</div>
								</div>
							</div>
						</div>
					</div>

					<div class="row">
						<div class="col-md-12">
							<div class="card">
								<div class="card-body">
									<h4 class="card-title">Weight & Dimensions</h4>
									<div class="row">
										<div class="col-md-4">
											<?php //kk($waight_price_chart);?>
											<label>Weight (in Kg)</label>
											<select class="form-control" name="uo_weight" required>
												<option value="">-- Select --</option>
												<?php foreach($waight_price_chart as $wpc):?>
													<option value="<?=$wpc->dpc_cat;?>"><?=$wpc->dpc_cat_comment;?></option>
												<?php endforeach;?>
											</select>
										</div>
										<div class="col-md-4">
											<div class="form-group">
												<label>Dimensions (in cms)</label>
												<div class="row">
													<div class="col-md-4">
													<input type="text" class="form-control" name="uo_dim_1" required> 
													</div>
													<div class="col-md-4">
													<input type="text" class="form-control" name="uo_dim_2" required>
													</div>
													<div class="col-md-4">
													<input type="text" class="form-control" name="uo_dim_3" required>
													</div>
												</div>
											</div>
										</div>
										<div class="col-md-4">
											<div class="form-group">
												<label>Is this a Cash on Delivery order?</label><br>
												<input type="radio" value="yes" name="uo_radio" required> Yes &nbsp;
												<input type="radio" value="no" name="uo_radio" required> No
											</div>
										</div>
										<div class="col-sm-6 col-md-3">  
											<label>Grand Total: <strong>Rs.</strong></label>
											<input type="submit" class="btn btn-success btn-block">
										</div>
									</div>
								</div>
							</div>
						</div>
					</div>

					<?=form_close();?>
					<!-- Search Filter -->
	            </div>
	        </div>
				<!-- /Page Content -->
				
				<!-- Add Address Modal -->
				<div id="add_address" class="modal custom-modal fade" role="dialog">
					<div class="modal-dialog modal-dialog-centered modal-lg">
						<div class="modal-content">
							<div class="modal-header">
								<h5 class="modal-title">Add Address</h5>
								<button type="button" class="close" data-dismiss="modal" aria-label="Close">
									<span aria-hidden="true">&times;</span>
								</button>
							</div>
							<div class="modal-body">
								<?=form_open('add-address', 'class="add-address" id="add-address" name="add-address"');?>
									<div class="row">
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">First Name <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_first_name" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Last Name <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_last_name" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Phone <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_phone" maxlength="10" minlength="10" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Alternate Phone </label>
												<input class="form-control" type="text" name="upa_phone2" maxlength="10" minlength="10">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Address Line 1 <span class="text-danger">*</span></label>
												<textarea class="form-control" type="text" name="upa_address" required></textarea>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Address Line 2 </label>
												<textarea class="form-control" type="text" name="upa_address2"></textarea>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Pincode <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_pin" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">City <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_city" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">State <span class="text-danger">*</span></label>
												<input class="form-control" type="text" name="upa_state" required>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Email <span class="text-danger">*</span></label>
												<input class="form-control" type="email" name="upa_email" required>
											</div>
										</div>
									</div>
									<div class="submit-section">
										<button class="btn btn-primary submit-btn">Submit</button>
									</div>
								<?=form_close();?>
							</div>
						</div>
					</div>
				</div>
				<!-- /Add Address Modal -->
				
				<!-- Edit Employee Modal -->
				<div id="edit_employee" class="modal custom-modal fade" role="dialog">
					<div class="modal-dialog modal-dialog-centered modal-lg" role="document">
						<div class="modal-content">
							<div class="modal-header">
								<h5 class="modal-title">Edit Employee</h5>
								<button type="button" class="close" data-dismiss="modal" aria-label="Close">
									<span aria-hidden="true">&times;</span>
								</button>
							</div>
							<div class="modal-body">
								<form>
									<div class="row">
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">First Name <span class="text-danger">*</span></label>
												<input class="form-control" value="John" type="text" name="">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Last Name</label>
												<input class="form-control" value="Doe" type="text" name="">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Username <span class="text-danger">*</span></label>
												<input class="form-control" value="johndoe" type="text" name="">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Email <span class="text-danger">*</span></label>
												<input class="form-control" value="johndoe@example.com" type="email">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Password</label>
												<input class="form-control" value="johndoe" type="password">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Confirm Password</label>
												<input class="form-control" value="johndoe" type="password">
											</div>
										</div>
										<div class="col-sm-6">  
											<div class="form-group">
												<label class="col-form-label">Employee ID <span class="text-danger">*</span></label>
												<input type="text" value="FT-0001" readonly class="form-control floating">
											</div>
										</div>
										<div class="col-sm-6">  
											<div class="form-group">
												<label class="col-form-label">Joining Date <span class="text-danger">*</span></label>
												<div class="cal-icon"><input class="form-control datetimepicker" type="text" name=""></div>
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Phone </label>
												<input class="form-control" value="9876543210" type="text" name="">
											</div>
										</div>
										<div class="col-sm-6">
											<div class="form-group">
												<label class="col-form-label">Company</label>
												<select class="select">
													<option>Global Technologies</option>
													<option>Delta Infotech</option>
													<option selected>International Software Inc</option>
												</select>
											</div>
										</div>
										<div class="col-md-6">
											<div class="form-group">
												<label>Department <span class="text-danger">*</span></label>
												<select class="select">
													<option>Select Department</option>
													<option>Web Development</option>
													<option>IT Management</option>
													<option>Marketing</option>
												</select>
											</div>
										</div>
										<div class="col-md-6">
											<div class="form-group">
												<label>Designation <span class="text-danger">*</span></label>
												<select class="select">
													<option>Select Designation</option>
													<option>Web Designer</option>
													<option>Web Developer</option>
													<option>Android Developer</option>
												</select>
											</div>
										</div>
									</div>
									<div class="table-responsive m-t-15">
										<table class="table table-striped custom-table">
											<thead>
												<tr>
													<th>Module Permission</th>
													<th class="text-center">Read</th>
													<th class="text-center">Write</th>
													<th class="text-center">Create</th>
													<th class="text-center">Delete</th>
													<th class="text-center">Import</th>
													<th class="text-center">Export</th>
												</tr>
											</thead>
											<tbody>
												<tr>
													<td>Holidays</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Leaves</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Clients</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Projects</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Tasks</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Chats</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Assets</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
												<tr>
													<td>Timing Sheets</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input checked="" type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
													<td class="text-center">
														<input type="checkbox">
													</td>
												</tr>
											</tbody>
										</table>
									</div>
									<div class="submit-section">
										<button class="btn btn-primary submit-btn">Save</button>
									</div>
								</form>
							</div>
						</div>
					</div>
				</div>
				<!-- /Edit Employee Modal -->
				
				<!-- Delete Employee Modal -->
				<div class="modal custom-modal fade" id="delete_employee" role="dialog">
					<div class="modal-dialog modal-dialog-centered">
						<div class="modal-content">
							<div class="modal-body">
								<div class="form-header">
									<h3>Delete Employee</h3>
									<p>Are you sure want to delete?</p>
								</div>
								<div class="modal-btn delete-action">
									<div class="row">
										<div class="col-6">
											<a href="javascript:void(0);" class="btn btn-primary continue-btn">Delete</a>
										</div>
										<div class="col-6">
											<a href="javascript:void(0);" data-dismiss="modal" class="btn btn-primary cancel-btn">Cancel</a>
										</div>
									</div>
								</div>
							</div>
						</div>
					</div>
				</div>
				<!-- /Delete Employee Modal -->
				
            </div>
			<!-- /Page Wrapper -->
			
        </div>
		<!-- /Main Wrapper -->

		<!-- jQuery -->
        <script src="<?=base_url('assets/backend/');?>js/jquery-3.2.1.min.js"></script>
		
		<!-- Bootstrap Core JS -->
        <script src="<?=base_url('assets/backend/');?>js/popper.min.js"></script>
        <script src="<?=base_url('assets/backend/');?>js/bootstrap.min.js"></script>
		
		<!-- Slimscroll JS -->
		<script src="<?=base_url('assets/backend/');?>js/jquery.slimscroll.min.js"></script>
		
		<!-- Select2 JS -->
		<script src="<?=base_url('assets/backend/');?>js/select2.min.js"></script>
		
		<!-- Datetimepicker JS -->
		<script src="<?=base_url('assets/backend/');?>js/moment.min.js"></script>
		<script src="<?=base_url('assets/backend/');?>js/bootstrap-datetimepicker.min.js"></script>
		<!-- Custom JS -->
		<script src="<?=base_url('assets/backend/');?>js/app.js"></script>
		<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.17.0/jquery.validate.min.js"></script>
	    <script type="text/javascript">
	        $(function(){
	          $("form[name='get-pin']").validate({
	            rules :{
	              uo_drop_pin:{
	                required: true,
	                minlength: 6,
	                maxlength: 6,
	                number: true
	              }
	            },
	            messages :{}
	          });
	        });
	    </script>
    </body>
</html>